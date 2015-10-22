import java.util.ArrayList;
import java.util.Scanner;

public class Project2Part1 {
	public static void main(String args[]) {
		/**
		 * TODO: PART1
		 */
		Project2 Eepu = new Project2();
		ArrayList<Token> tokens = Eepu.read_input();
		Parser pBoi = new Parser(tokens);
		pBoi.build_expression_tree(tokens);
		}
}