#include <iostream>
#include <iostream>
#include <string>
#include "graph.h"
#define INFI 1000000
using namespace std;

/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph. Read in data from the input
// and set up your data structures here.
Graph::Graph(int Vertices, int routes)
{
	this->numAirports = Vertices;
    visited = new bool [numAirports];
    predecessor = new int[numAirports];
    distance = new double[numAirports];
    adj = new double* [numAirports];
    airports = new string [numAirports];
    fL = new string [numAirports];
    stringCounter = 0;
    for (int i = 0; i < numAirports; i++){
        adj[i] = new double [numAirports];
        airports[i] = "";
        fL[i] = "";
        visited[i] = false;
        predecessor[i] = -1;
        distance[i] = INFI;
        for(int j = 0; j < numAirports; j++)
        {
            adj[i][j] = 0;
        }
    }
	/*airports = new AdjList[Vertices];
	for (int i = 0; i < Vertices; i++) {
		airports[i].head = NULL;
		airports[i].nameAirport = "";
	}*/
}

int Graph::minDistance(double dist[], bool sptSet[])
{
   // Initialize min value
   int min = INFI, min_index;
 
   for (int v = 0; v < numAirports; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}


void Graph::dijk(int A, int B) {
    
    double dist[numAirports];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 	int counter = -1;
    int flag = 0;
    bool sptSet[numAirports]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
    
    int path[numAirports];
     for (int i = 0; i < numAirports; i++) {
     	dist[i] = INFI;
    	sptSet[i] = false;
        path[i] = -1;
     }
     dist[A] = 0;
     for (int count = 0; count < numAirports; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 		
       // Mark the picked vertex as processed
       sptSet[u] = true;
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < numAirports; v++) {
       		if (!sptSet[v] && adj[u][v] && dist[u] != INFI && dist[u]+adj[u][v] < dist[v]) {
         	    dist[v] = dist[u] + adj[u][v];
                path[v] = u;
            }   
       }
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
    }
 	//if (path[B] == -1) {
      //          path[B] = ++counter;
    //}

     // print the constructed distance array
     if (dist[B] == INFI) {
     	cout << "not possible\n";
     }
     else {
        cout << airports[A] << " ";

        pathPrinter(path, B);

        printf("%.2f\n", dist[B]);
     	}
    }


void Graph::pathPrinter(int * path, int dest) {
    if (path[dest] == -1) {
        return;
    }
    pathPrinter(path, path[dest]);
    cout << airports[dest] << " ";
}

void Graph::addRoute(string from, string to, double cost) {

	int origin,destin;
	int flag = 0;
	for (int i = 0; i < numAirports;i++) {
		if (airports[i] == from) {
			flag = 1;
			origin = i;
			break;
		}
	}

	if (flag == 0) {
		for (int i = 0; i < numAirports; i++) {
			if (airports[i] == "") {
				airports[i] = from;
				origin = i;
				break;
			}
		}
	}
	flag = 0;
	for (int i = 0; i < numAirports;i++) {
		if (airports[i] == to) {
			flag = 1;
			destin = i;
			break;
		}
	}
	if (flag == 0) {
		for (int i = 0; i < numAirports; i++) {
			if (airports[i] == "") {
				airports[i] = to;
				destin = i;
				break;
			}
		}
	}


	if( origin > numAirports || destin > numAirports || origin < 0 || destin < 0)
            {   
                cout<<"Invalid edge!\norigin:" << origin << " & destin: " << destin <<endl;
            }
            else
            {
            	adj[origin][destin] = cost;
            	adj[destin][origin] = cost;
            }
}


	/*AdjListNode* newNode = newAdjListNode(to, cost);
	int source, destination;
	int flag = 0;

	for (int i = 0; i < numAirports;i++) {
		if (airports[i].nameAirport == from) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		int temp = 0;
		while (airports[temp].nameAirport != "") {
			temp++;
		}
		airports[temp].nameAirport = from;
	}

	flag = 0;
	for (int i = 0; i < numAirports;i++) {
		if (airports[i].nameAirport == to) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		int temp = 0;
		while (airports[temp].nameAirport != "") {
			temp++;
		}
		airports[temp].nameAirport = to;
	}


	for (int i = 0; i < numAirports; i++) {
		if (airports[i].nameAirport == from) {
			source = i;
		}
		else if ( airports[i].nameAirport == to) {
			destination = i;
		}
	}
    newNode->next = airports[source].head;
    airports[source].head = newNode;
    newNode = newAdjListNode(from, cost);
    newNode->next = airports[destination].head;
    airports[destination].head = newNode;*/


void Graph::display()
        {
            int i,j;
            for (int m = 0; m < numAirports; m++) {
            	cout << airports[m] << "\t";
            }
            cout << endl;
            for(i = 0;i < numAirports;i++)
            {	
                for(j = 0; j < numAirports; j++)
                    cout<<mst[i][j]<<"  ";
                cout<<endl;
            }
        }



AdjListNode* Graph::newAdjListNode(string name, double price)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->name = name;
            newNode->price = price;
            newNode->next = NULL;
            return newNode;
        }
// Code for part 1. Print out the sequence of airports and price
// of the trip.
void Graph::find_ticket(const string &source,const string &destination)
{
	int src, dst;
	for (int i = 0; i < numAirports;i++) {
		if (airports[i] == source) {
			src = i;
			break;
		}
	}
	for (int i = 0; i < numAirports;i++) {
		if (airports[i] == destination) {
			dst = i;
			break;
		}
	}
	dijk(src, dst);
    /*if (sp == 0) {
    	cout << "not possible\n";
    }
    else {
    	cout << source << " " << destination;
    	printf(" %.2f\n", sp);
    }
    for (int i = 0; i< numAirports; i++) {
  		visited[i] = false;
  		distance[i] = INFI;
    }*/
 }

// Code for part 2. Print out the tour sequence or "not possible"
// if not all cities can be visited.
void Graph::eulerian_tour(int pos)
{
    fL[stringCounter++] = airports[pos];
    visited[pos] = true;

    for (int i = 0; i < numAirports; i++) {
        if (visited[i] == false && mst[pos][i] != 0 && mst[pos][i] != INFI) {
            eulerian_tour(i);
        }
    }
}

void Graph::printP2() {
    for (int i = 0; i < numAirports; i++) {
        if (fL[i] != "") {
            cout << fL[i] << endl;
        }
    }

}

void Graph::sort() {
    for (int i = 0; i < numAirports; i++) {
        for (int j = i; j < numAirports; j++) {
            if (airports[i] > airports[j]) {
                string temp = airports[j];
                airports[j] = airports[i];
                airports[i] = temp;
                double * t = mst[j];
                mst[j] = mst[i];
                mst[i] = t;
                for (int k = 0; k < numAirports;k++) {
                    double num = mst[k][j];
                    mst[k][j] = mst[k][i];
                    mst[k][i] = num;
                }
            }
        }
    }
}

int Graph::find(string airport) {
    for (int i = 0; i < numAirports; i++) {
        if (airports[i] == airport) {
            return i;
        }
    }
    return -1;
}


int Graph::primMST()
{
     mst = new double *[numAirports];
     int parent[numAirports]; // Array to store constructed MST
     double key[numAirports];   // Key values used to pick minimum weight edge in cut
     bool mstSet[numAirports];  // To represent set of vertices not yet included in MST
    
     for (int i = 0; i < numAirports; i++){
        mst[i] = new double [numAirports];
     }


     for (int i = 0; i < numAirports;i++) {
        for (int j = 0; j < numAirports; j++) {
            mst[i][j] = INFI;
        }
     }


     // Initialize all keys as INFINITE
     for (int i = 0; i < numAirports; i++)
        key[i] = INFI, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < numAirports - 1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
        if (u == -1) {
            return -1;
        }
        //cout<< endl;

        // Add the picked vertex to the MST Set
        mstSet[u] = true;
    
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < numAirports; v++) {
            if (adj[u][v] && mstSet[v] == false && adj[u][v] <  key[v]) {
                parent[v]  = u;
                key[v] = adj[u][v];
            }

        }
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
        //cout << u << endl;   
     }
     //cout << "here" <<endl;

     for (int i = 1; i < numAirports; i++) {
        int temp = parent[i];
       // cout << "reached here\n";
       // cout << "temp = " << temp << ", i = " << i << " and adj[i][temp] = " << adj[i][temp] << endl;
        mst[temp][i] = adj[i][temp];
        
        mst[i][temp] = adj[i][temp];

     }
     return 1;
 
     // print the constructed MST
}

int Graph::minKey(double key[], bool mstSet[])
{
   // Initialize min value
   int min = INFI;
   int min_index = INFI;
    
   for (int v = 0; v < numAirports; v++)
     if (mstSet[v] == false && key[v] < min) {
         min = key[v];
         min_index = v;
     }
     if (min_index > numAirports || min_index == INFI) {
        min_index = -1;
     }
   return min_index;
}















