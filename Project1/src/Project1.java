import java.awt.Point;
import java.util.ArrayList;
import java.util.Scanner;

public class Project1 {
	private int m;
	private int n;
	private WeightedQuickUnionUF qu;
	private int[][] grid;
	private ArrayList<Point> connections;

	/**
	 * initializes UnionFind structure, grid and connection list
	 * @param m
	 * @param n
	 */
	public Project1(int m, int n){
		this.m = m;
		this.n = n;
		grid = new int[m][n];
		qu = new WeightedQuickUnionUF(m*n);
		connections = new ArrayList<Point>();
	}

	/**
	 * Reads input from user (pair of connections presented as points), store the input in a list  
	 */
	public void read_input() {
		
		System.out.print("Enter number of pairs of connections: ");
		int conn = StdIn.readInt();
		for (int i = 0; i < conn; i++) {
			int i1 = StdIn.readInt();
			int i2 = StdIn.readInt();
			int i3 = StdIn.readInt();
			int i4 = StdIn.readInt();
			Point p1 = new Point(i1, i2);
			Point p2 = new Point(i3, i4);
			connections.add(p1);
			connections.add(p2);
		}		
	}

	/**
	 * converts point into an integer
	 * @param p
	 * @return
	 */

	public int map(Point p) {
		int point = 0;
		//for (int i = 0; i < p.getX(); i++) {
			//for (int j = 0; j < p.getY(); j++) {
				//point++;
			//}
		point += ((this.n * p.getX()) + p.getY());
		return point;
	}

	/***
	 * converts integer into a point
	 * @param i
	 * @return
	 */
	public  Point unmap(int i) {
		int pointX = 0;
		int pointY = 0;
		pointY = (i % n);
		pointX = (i - pointY) / n;
		Point p = new Point(pointX, pointY);
		return p;
	}

	/***
	 * scans connections and populates UnionFind structure
	 */
	public void process_connections(){
		for (int i = 0; i < connections.size(); i += 2) {
				if(is_adjacent(connections.get(i), connections.get(i+1))) {
					int x = map(connections.get(i));
					int y = map(connections.get(i+1));
					qu.union(x, y);
				}
		}
	}

	/**
	 * retrieve the connected sets from the UnionFind structure
	 * @return connected sets
	 */
	public ArrayList<Point> retrieve_connected_sets() {
		return null;
	}

	/**
	 * Tests whether two Cells are connected in the grid
	 * @param p1
	 * @param p2
	 * @return
	 */
	public boolean is_adjacent(Point p1, Point p2) {
		if (Math.abs(p1.getX()-p2.getX()) <= 1) {
			if (Math.abs(p1.getY() - p2.getY()) <= 1) {
				return true;
			}
		}
		return false;
	}

	/**
	 * outputs the boundaries and size of each connected set
	 * @param sets
	 */
	public void output_boundaries_size(ArrayList<Point> sets) {
		
	}

	public static void main(String args[]) {
		int m, n;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter size of grid(m n): ");
		m = input.nextInt();
		n = input.nextInt();

		Project1 project1 = new Project1(m,n);
		project1.read_input();
		project1.process_connections();
		ArrayList<Point> sets = project1.retrieve_connected_sets();
		project1.output_boundaries_size(sets);
        input.close();
       	}
}