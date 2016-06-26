#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Main function for sorting the file
void extern_sort(string in_fname, string out_fname,
		string chunk_location, int chunk_size);

// Pick your favorite n*log(n) sorting algorithm here!
void sort(string a[], int low, int high);

int partition (string arr[], int low, int high);

void swap(string a[], int i, int j);

// Write a temporary chunk file
void write_chunk(string fileName, int numItems);

// Merges the k temporary files
void k_merge(string chunk_location, string out_fname, int num_chunks, long total, int chunk_size);
int min(string container[], int chunk_size);
void mergeKlists(ifstream list[], int from, int to);
//ifstream[] mergeTwoLists(ifstream list1[], ifstream list2[]);