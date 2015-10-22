import java.util.ArrayList;


public class Parser {
	static int tokenPt;
	Token currentTk;
	
	//List of defined token constants
		final int Tk_LEFT_PARENTHESES = 21;
		final int Tk_RIGHT_PARENTHESES = 22;
		final int Tk_ADDITION = 23;
		final int Tk_SUBTRACTION = 24;
		final int Tk_MULTIPLY = 25;
		final int Tk_DIVIDE = 26;
		final int Tk_INT = 11;
		final int Tk_FLOAT = 12;
	
	public Parser(ArrayList<Token> tokens) {
		tokenPt = 0;
		this.getNextTk(tokens);
	}
		
	public void getNextTk(ArrayList<Token> tokens) {
		if(tokenPt >= tokens.size()) {
			return;
		}
		currentTk = tokens.get(tokenPt++);
	}

	//Expression function: Building the expression tree starts here. First, all
	//multiplication/division operations are placed into tree nodes, then the
	//remaining addition/subtraction operations are placed into tree nodes.
	public Tree build_expression_tree(ArrayList<Token> tokens) {
				if (currentTk.getToken() == 28) {
					getNextTk(tokens);
					build_expression_tree(tokens);
				}
				if (currentTk.getToken() == 21 || currentTk.getToken() == 22) {
					getNextTk(tokens);
					build_expression_tree(tokens);
				}
				Tree F1 = factorBuilder(tokens);
				F1.print();
				System.out.println();
				Project2 PJ = new Project2();
				Tree temp1 = PJ.evaluate(F1);
				temp1.get_info().print();
				System.out.println();
				//getNextTk(tokens);
				
				while (currentTk.getToken() == 28) {
					getNextTk(tokens);
					if (currentTk.getToken() == 28) {
						continue;
					}
					else if (currentTk.getToken() == 20) {
						break;
					}
					else if (currentTk.getType() != 's') {
						build_expression_tree(tokens);
					}
					else if (currentTk.getToken() == 21 || currentTk.getToken() == 22) {
						continue;
					}
					else {
						getNextTk(tokens);
					}
				}
				return temp1;
	}

	
	public Tree factorBuilder(ArrayList<Token> tokens) {
		Tree P1 = Factor(tokens);
		while(currentTk.getToken() == Tk_ADDITION || currentTk.getToken() == Tk_SUBTRACTION) {
			Tree root = new Tree(currentTk);
			getNextTk(tokens);
			Tree P2 = Factor(tokens);
			root.set_left(P1);
			root.set_right(P2);
			P1 = root;
		}
		return P1;
	}
	//Factor function: While there are multiplication/division operations to be
	//performed, get the next tokens and make a new factor tree node. Then if there
	//are no operands, return the next primary tokens.
	public Tree Factor(ArrayList<Token> tokens) {
		Tree P1 = Primary(tokens);
		while(currentTk.getToken() == Tk_MULTIPLY || currentTk.getToken() == Tk_DIVIDE) {
			Tree root = new Tree(currentTk);
			getNextTk(tokens);
			Tree P2 = Primary(tokens);
			root.set_left(P1);
			root.set_right(P2);
			P1 = root;
		}
		return P1;
	}
	

	//Primary function: This function first checks for the beginning of an expression
	//contained in parentheses, then calls the expression function to place this enclosed
	//expression into a tree node. If there is no parentheses, this function returns the
	//next token (which in this project is an int or a float).
	public Tree Primary(ArrayList<Token> tokens){
		if(currentTk.getToken() == 21) {// '('
			getNextTk(tokens);
			Tree E1 = build_expression_tree(tokens);
			if(currentTk.getToken() != 22) {// ')'
				System.out.println("Missing ')'");
			} else {
				getNextTk(tokens);
			}
			return E1;
		}
		else if(currentTk.getToken() == Tk_INT || currentTk.getToken() == Tk_FLOAT) {
			Tree arg = new Tree(currentTk);
			getNextTk(tokens);
			return arg;
		}
		else {
			System.out.println("something is wrong");
			System.exit(1);
			return null;
		}
	}
}