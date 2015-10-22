import java.util.ArrayList;
import java.util.Scanner;

public class Project0 {
	static ArrayList<Token> tokens = new ArrayList<Token>();
	static String input = "";
	
	public ArrayList<Token> get_tokens(String input) {
		for (int i = 0; i < input.length(); i++) {
			if (Character.isSpaceChar(input.charAt(i))) {
				continue;
				}
				else if (input.charAt(i) == '\n') {
					continue;
				}
				else if (Character.isDigit(input.charAt(i))) {
					String number = ""; boolean isFloat = false; int dC = 0;
					while (Character.isDigit(input.charAt(i)) || input.charAt(i) == '.') {
						if (input.charAt(i) == '.') {
							dC++; isFloat = true;
						}
						if (dC > 1) {
							break;
						}
						number += input.charAt(i);
						i++;
					}
					if (isFloat) {
						float y = Float.parseFloat(number);
						Token t = new Token(12, y);
						tokens.add(t);
					}
					else {
						int y = Integer.parseInt(number);
						Token t = new Token(11, y);
						tokens.add(t);
					}
				}
				else if (input.charAt(i) == '(') {
					Token t = new Token(21,"(");
					tokens.add(t);
				} 
				else if (input.charAt(i) == '?') {
					Token t = new Token(20,"?");
					tokens.add(t);
				}
				else if (input.charAt(i) == ')') {
					Token t = new Token(22,")");
					tokens.add(t);
				}
				else if (input.charAt(i) == '+') {
					Token t = new Token(23,"+");
					tokens.add(t);
				}
				else if (input.charAt(i) == '-') {
					Token t = new Token(24,"-");
					tokens.add(t);
				}
				else if (input.charAt(i) == '*') {
					Token t = new Token(25,"*");
					tokens.add(t);
				}
				else if (input.charAt(i) == '/') {
					Token t = new Token(26,"/");
					tokens.add(t);
				}
				else if (input.charAt(i) == '.') {
					Token t = new Token(27,".");
					tokens.add(t);
				}
				else if (input.charAt(i) == ';') {
					Token t = new Token(28,";");
					tokens.add(t);
				}
				else if (input.charAt(i) == '=') {
					Token t = new Token(29,"=");
					tokens.add(t);
				}
				else continue;
			}
			return tokens;
	}
	
	public String read_input(Scanner in) {	
		if (!in.hasNext()) {
			System.out.println("End of File reached");
			return "";
		}
		else {
			while (in.hasNext()) {
				String temp = in.nextLine();
				if (temp.contains("?")) {
					int i = 0;
					while (temp.charAt(i) != '?') {
						input += temp.charAt(i);
						i++;
					}
					input += '\n';	
					break;
				}
				input += temp;
				input += '\n';
			}
			input += "?";
			return input;
		}
	}
	
	public void print_tokens(ArrayList<Token> tokens) {
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens.get(i).getType() == 's') {
				System.out.print("(" + tokens.get(i).getToken() + ",0)");
			}
			else if (tokens.get(i).getType() == 'f') {
				System.out.print("(" + tokens.get(i).getToken() + "," + tokens.get(i).getValue_f() + ")");
			}
			else {
				System.out.print("(" + tokens.get(i).getToken() + "," + tokens.get(i).getValue_i() + ")");
			}
		}
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		Project0 p0 = new Project0();
		input = p0.read_input(in);
		tokens = p0.get_tokens(input);
		p0.print_tokens(tokens);
		in.close();
	}
}