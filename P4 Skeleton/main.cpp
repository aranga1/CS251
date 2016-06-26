#include <iostream>
#include <string>
#include "ExternalSort.h"
#include "ExternalSearch.h"

using namespace std;

int main(int argc, const char* argv[])
{	
	if(argv[1] == string("1")) // Run P4 Part 1
	{
        int nLines = atoi(argv[4]);
		extern_sort(argv[2], argv[3], argv[5],nLines);
	}
	else if(argv[1] == string("2"))
	{
        string fileName = argv[2];
        int temp = 3;
        while (temp < argc) {
            if (extern_search(fileName,argv[temp])) {
                cout << "found\n";
            }
            else {
                cout << "missing\n";
            }
            temp++;
        }
	}
	return 0;
}