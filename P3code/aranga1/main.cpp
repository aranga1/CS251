#include <iostream>
#include <cstdlib>
#include <cstring>

#include "heap.h"

using namespace std;
int* table1;
int* table2;
int r, m, num;
char operation;

void rehash();
void insert(int number);


void insert(int n) {
    //inserts the element n in th cuckoo hash table (correct array)
    int number = n;
    if (table1[number % r] == number) {
        cout << number << " already in T1[" << number % r << "]\n";
        return;
    }
    if (table2[number % (r-1)] == number) {
        cout << number << " already in T2[" << number % (r - 1) << "]\n";
        return;
    }
    int temp;
    for (int i = 0; i < m; i++) {
        temp = number;
        if (table1[temp % r] == 0) {
            table1[temp % r] = temp;
            cout << temp << " in T1[" << temp % r << "]!\n";
            return;
        }
        number = table1[temp % r];
        table1[temp % r] = temp;
        cout << temp << " in T1[" << temp % r << "]\n";
        temp = number;
        if (table2[temp % (r-1)] == 0) {
            table2[temp % (r - 1)] = temp;
            cout << temp << " in T2[" << temp % (r - 1) << "]!\n";
            return;
        }
        number = table2[temp % (r - 1)];
        table2[temp % (r - 1)] = temp;
        cout << temp << " in T2[" << temp % (r - 1) << "]\n";
        temp = number;
    }
    cout << "maxloop reached" << endl;
    rehash();
    insert(temp);
}


void rehash() {
    //rehashes the two arrays with couble the previous sizes and puts the elements back in the new arrays in their new hash based positions
    int * table1New = table1;
    int * table2New = table2;
    int rTemp = r;
    r = r * 2;
    
    table1 = new int[r];
    table2 = new int[r];
    
    for (int i = 0; i < r; i++) {
        table1[i] = 0;
        table2[i] = 0;
    }
    for (int i = 0; i < rTemp; i++) {
        if (table1New[i] != 0) {
            insert(table1New[i]);
        }
        if (table2New[i] != 0) {
            insert(table2New[i]);
        }
    }
}

void lookup(int number) {
    //checks if a given number is anywhere in the system already.
    if (table1[number % r] == number) {
        cout << number << " at T1[" << number % r << "]\n";
    }
    else if (table2[number % (r-1)] == number) {
        cout << number << " at T2[" << number % (r - 1) << "]\n";
    }
    else {
        cout << "no " << number << endl;
    }
}

void remove(int number) {
    //removes a number from its position in the system, if it exists
    if (table1[number % r] == number) {
        cout << number << " out T1[" << number % r << "]\n";
        table1[number % r] = 0;
    }
    else if (table2[number % (r-1)] == number) {
        cout << number << " out T2[" << number % (r - 1) << "]\n";
        table2[number % (r - 1)] = 0;
    }
    else {
        cout << "no out " << number << endl;
    }
}

void CuckooHashing() {
    //cuckoohashing main method. Does the whole hashing
    cin >> r;
    cin >> m;
    table1 = new int[r];
    table2 = new int[r];
    for (int i = 0; i < r; i++) {
        table1[i] = 0;
        table2[i] = 0;
    }
    while (cin >> operation) {
        //cin >> operation;
        cin >> num;
        switch (operation) {
            case 'i':
                //tough part (a little. U got this :) )
                //Calls insert
                insert(num);
                break;
            case 'r':
                //Calls remove
                remove(num);
                break;
            case 'l':
                //Calls lookup
                lookup(num);
                break;
            }
    }
    // TODO : add your logic here.
}

void Heap() {
    int n, key, value;
    BinaryHeap heap (false);
    char command;
    cin >> n;
    while (n--) {
        cin >> command;
        switch (command) {
            case 'c':
            {
                cin >> value;
                if (value == 1) {
                    heap.setMaxHeap(true);
                }
                else {
                    heap.setMaxHeap(false);
                }
                break;
            }
            case 'e':
            {
                TreeNode * t = heap.extract();
                if (t == NULL) {
                    cout << "empty\n";
                }
                else {
                    cout << t->key << " " << t->value << endl;
                }
                break;
            }
            case 'i':
            {
                cin >> key;
                cin >> value;
                TreeNode* node = new TreeNode(key, value);
                heap.insert(node);
                break;
            }
            case 'p':
            {
                heap.peek();
                break;
            }
            case 'h':
                int numInts;
                int currentNum;
                cin >> numInts;
                while (numInts--) {
                    cin >> currentNum;
                    TreeNode * element = new TreeNode(currentNum, 0);
                    heap.insert(element);
                }
                break;
            case 's':
            {
                cout << heap.sizeHeap() << endl;;
                break;
            }
            default:
                cout << "Wrong input" << endl;
        }
    }
}

void HeapSort() {
    int order, num, key, value;
    BinaryHeap heap (false);
    cin >> order;
    cin >> num;
    if (order == 1) {
        heap.setMaxHeap(false);
    }
    else {
        heap.setMaxHeap(true);
    }
    while (num--) {
        cin >> key >> value;
        TreeNode * element = new TreeNode(key, value);
        heap.insert(element);
    }
    char command;
    cin >> command;
    if (command == 'q') {
        heap.heapSort();
    }
    cout << endl;
}


/* Main function */
int main(int argc, char** argv) {

    /* Read the option */
    int option;
    std::cin >> option;

    /* Call the respective function */
    switch(option) {

        /* Cuckoo Hashing */
        case 1:
            CuckooHashing();
        break;

        /* Binary Heap */
        case 2:
            Heap();
        break;
        
        case 3:
            HeapSort();
        break;

        /* Wrong option */
        default:
            std::cout << "Wrong option" << std::endl;

    }

    /* Close the program */
	return 0;
}

