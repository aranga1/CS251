/**
 *  CS251 - Spring 2016: Project 1 Solution
 */

#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;


void printline(int number) {
    int printtimes = (6*number)-3;
    for (int i = 0; i < printtimes; i++) {
        cout << "-";
    }
    cout << endl;
    
}

int main(int argc, char** argv)
{
    /* Use either optionA or optionB: */

    /* Option A: input/output using C like notation */
    FILE *inputfile = stdin;
	FILE *outputfile = stdout;
    int size;
	/* Option B: input/output using C++ like notation would use "cin" and "cout" to read/write to stdin/stdout */
    cin >> size;
    int n = 0;
    int num;
    printline(size);
    while (cin >> num) {
        n++;
        if (n % size == 0 && n != 0) {
            cout << setw(3) << num << endl;
            continue;
        }
        printf("%3d | ", num);
    }
    printline(size);
    
    /* ------------------------------------ */
    /* process input files and write output */
    /* ------------------------------------ */
    
	
    /* Close files if using C like notation */
    fclose(inputfile);
    fclose(outputfile);

    /* Exit the program */
    return 0;
}


