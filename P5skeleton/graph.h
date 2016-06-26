#include <iostream>
#include <string>

using namespace std;

struct AdjListNode
{
	double price;
	string name;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode* head;
	string nameAirport;
};

class Graph
{
	public:
		int numAirports;
		int numRoutes;
		double **adj;
		double **mst;
		int *predecessor;
		double *distance;
		string *airports;
		string *fL;
		int stringCounter;
		bool *visited;
		// Constructor
		Graph(int Vertices, int routes); 
		
		// Part 1: Find a ticket using Dijkstra
		void find_ticket(const string &source,const string &destination); 
		void addRoute(string from, string to, double cost);
		void printGraph();
		void display();
		void dijk(int A, int B);
		int minDistance(double dist[], bool sptSet[]);
		void printSolution(int dist[]);
		void printP2();
		void pathPrinter(int * path, int dest);
		int primMST();
		int minKey(double key[], bool mstSet[]);
		AdjListNode* newAdjListNode(string name, double price);
		void sort();
		int find(string airport);
		
		
		// Part 2: Try to do a tour of all cities
		void eulerian_tour(int pos); 
	
	// Add any needed private methods here
};