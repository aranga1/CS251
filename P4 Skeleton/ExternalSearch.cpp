#include "ExternalSearch.h"
#include <fstream>

bool extern_search(string fileName, string toFind)
{
    ifstream is;
    //cout << fileName << endl;
    is.open(fileName);
    
    
    char c;
    is.seekg(0, is.end);
    long a = is.tellg();
    is.seekg(0, is.beg);
    long start = 0;
    long end = a;
    long mid;
    string line;
    while (start < end) {
        mid = (start + end) / 2;
        is.seekg(mid, is.beg);
        while ((c = is.peek())!= '\n' && is.tellg() != 0) {
            is.seekg(-1, is.cur);
            //cout << c << endl;
        }
        if (is.peek() == '\n') {
            is.seekg(+1, is.cur);
        }
        getline(is, line);
        if (line == toFind) {
            return true;
        }
        if (line < toFind) {
            start = mid + 1;
        }
        else if (line > toFind) {
            end = mid;
        }
    }
    return false;
}
