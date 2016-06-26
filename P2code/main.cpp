//EEHITA
#include <iostream>
#include "stack.h"
#include "deque.h"
#include <utility>

using namespace std;
int cols;

void wordFinder(char **matrix, int num_rows, int num_cols, string word) {
    int curr_char = 0;
    Stack::Stack stack;
    int i = 0;
    int j = 0;
    int ct = 0;
    int prev_selectionX, prev_selectionY, dont_start_atX, dont_start_atY;
    //prev_selectionX = prev_selectionY = 0;
    while (i < num_rows) {
        //cout << "while loop 1 \n";
        while (j < num_cols) {
            //cout << "while loop 2 \n";
            if (curr_char == word.length()) {
                stack.print();
                exit(1);
            }
            else if (matrix[i][j] == word[word.length() - 1] && curr_char == word.length()-1) {
                //cout << "entered main\n";
                stack.push(make_pair (i,j));
                stack.print();
                exit(1);
            }
            else if (matrix[i][j] == word[curr_char]) {
                //cout << "i,j -> " << i << "," << j << endl;
                ct++;
                stack.push(make_pair (i,j));
                //prev_selectionX = i;
                //prev_selectionY = j;
              //  cout << "Pushed to stack values of letter " << word[curr_char] << "\t " << i<<j<<endl;
                curr_char++;
                //cout << "Found letter " << word[curr_char-1];//<< "\nPrevious x,y = " << prev_selectionX << "," << prev_selectionY << "\n";
                //cout << " now looking for letter " << word[curr_char] << " in " << word << endl;
                //surrounding cell search
                //cout << "i,j -> " << i << " " << j << " and previous x y -> " << prev_selectionX << " " << prev_selectionY << endl;
                if (matrix[i][j] == word[curr_char] && (i != prev_selectionX || j != prev_selectionY)) {
                    continue;
                }
                else if (i == 0) {
                    if (j > 0 && j < num_cols) {
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j = j+1;
                            continue;
                        }
                        else if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j = j-1;
                            continue;
                        }
                        else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i = i+1;
                            continue;
                        }
                        else if (matrix[i+1][j+1] == word[curr_char] && (i+1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i++; j++;
                            continue;
                        }
                        else if (matrix[i+1][j-1] == word[curr_char] && (i+1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i++; j--;
                            continue;
                        }
                    }
                    else if (j == 0) {
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j++;
                            continue;
                        }
                        else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i+1][j+1] == word[curr_char] && (i+1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i++; j++;
                            continue;
                        }
                    }
                    else if (j == num_cols-1) {
                        if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i+1][j-1] == word[curr_char] && (i+1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i++; j--;
                            continue;
                        }
                    }
                }
                else if (j == 0) {
                    //cout << "entered j" << endl;
                   // cout << "num rows -> " << num_rows << " i ->" << i<< " j ->" << j<< endl;
                    
                    if (i > 0 && i < num_rows - 1) {
                        //cout << "orint this \n";
                        if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            //cout << "K found ->" << matrix[i][j];
                            continue;
                        }
                        else if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j++;
                            continue;
                        }
                        else if (matrix[i+1][j+1] == word[curr_char] && (i+1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i++; j++;
                            //cout << "found correct letter! \nLetter is -> " << matrix[i][j] << endl;
                            continue;
                        }
                        else if (matrix[i-1][j+1] == word[curr_char] && (i-1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i--; j++;
                            continue;
                        }
                    }
                    else if (i == 0) {
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j++;
                            continue;
                        }
                        else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i+1][j+1] == word[curr_char] && (i+1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i++; j++;
                            continue;
                        }
                    }
                    else if (i == num_rows-1) {
                        //cout<<"entered here\n";
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j++;
                            //cout << "yo\n";
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i-1][j+1] == word[curr_char] && (i-1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i--; j++;
                            continue;
                        }
                    }
                }
                else if (i == num_rows - 1) {
                    if (j > 0 && j < num_cols) {
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j = j+1;
                            continue;
                        }
                        else if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j = j-1;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i = i-1;
                            continue;
                        }
                        else if (matrix[i-1][j+1] == word[curr_char] && (i-1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i--; j++;
                            continue;
                        }
                        else if (matrix[i-1][j-1] == word[curr_char] && (i-1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i--; j--;
                            continue;
                        }
                    }
                    else if (j == 0) {
                        if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                            j++;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i-1][j+1] == word[curr_char] && (i-1 != prev_selectionX || j+1 != prev_selectionY)) {
                            i--; j++;
                            continue;
                        }
                    }
                    else if (j == num_cols-1) {
                        if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j--;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i-1][j-1] == word[curr_char] && (i-1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i--; j--;
                            continue;
                        }
                    }
                }
                else if (j == num_cols-1) {
                    if (i > 0 && i < num_rows) {
                        if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j--;
                            continue;
                        }
                        
                        else if (matrix[i+1][j-1] == word[curr_char] && (i+1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i++; j--;
                            continue;
                        }
                        else if (matrix[i-1][j-1] == word[curr_char] && (i-1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i--; j--;
                            continue;
                        }
                    }
                    else if (i == 0) {
                        if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j--;
                            continue;
                        }
                        else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                            i++;
                            continue;
                        }
                        else if (matrix[i+1][j-1] == word[curr_char] && (i+1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i++; j--;
                            continue;
                        }
                    }
                    else if (i == num_rows-1) {
                        if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                            j--;
                            continue;
                        }
                        else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                            i--;
                            continue;
                        }
                        else if (matrix[i-1][j-1] == word[curr_char] && (i-1 != prev_selectionX || j-1 != prev_selectionY)) {
                            i--; j--;
                            continue;
                        }
                    }
                }
                else {
                    //cout << "reached here\n";
                   // cout << "entered last option with i & j -> " << i << "," << j << endl;
                   // cout << word[curr_char] << " location i+1 & j in matrix is " << matrix[i+1][j] << endl;
                    if (matrix[i][j+1] == word[curr_char] && (i != prev_selectionX || j+1 != prev_selectionY)) {
                        j++;
                        //cout << "1";
                        continue;
                    }
                    else if (matrix[i][j-1] == word[curr_char] && (i != prev_selectionX || j-1 != prev_selectionY)) {
                        j--;
                        //cout << "2";
                        continue;
                    }
                    else if (matrix[i+1][j-1] == word[curr_char] && (i+1 != prev_selectionX || j-1 != prev_selectionY)) {
                        i++; j--;
                        //cout << "3";
                        continue;
                    }
                    else if (matrix[i+1][j+1] == word[curr_char] && (i+1 != prev_selectionX || j+1 != prev_selectionY)) {
                        i++; j++;
                        //cout << "Found correct letter! \nLetter is -> " << matrix[i][j] << endl;
                        //cout << "i & j -> " << i << j << endl;
                        continue;
                    }
                    else if (matrix[i+1][j] == word[curr_char] && (i+1 != prev_selectionX || j != prev_selectionY)) {
                        i++;
                        //cout << "Found correct letter! \nLetter is -> " << matrix[i][j]; //doesnt enter this...
                        continue;
                    }
                    else if (matrix[i-1][j] == word[curr_char] && (i-1 != prev_selectionX || j != prev_selectionY)) {
                        i--;
                        //cout << "6";
                        continue;
                    }
                    else if (matrix[i-1][j-1] == word[curr_char] && (i-1 != prev_selectionX || j-1 != prev_selectionY)) {
                        i--; j--;
                        //cout << "7";
                        continue;
                    }
                    else if (matrix[i-1][j+1] == word[curr_char] && (i-1 != prev_selectionX || j+1 != prev_selectionY)) {
                        i--; j++;
                        //cout << "Found currect letter! \nLetter is -> " << matrix[i][j] << endl;
                        continue;
                    }
                }
                //cout << "Letter not found\n";
                curr_char = curr_char - 2;
                if (curr_char == 0) {
                    //cout << "previous i and j -> " << i << " " << j << endl;
                    pair<int,int> tesafasd = stack.pop();
                    pair<int,int> temp = stack.pop();
                    i = temp.first;
                    j = temp.second + 1;
                    //cout << j << endl;
                    //cout << "this happened: Now the current positions would be -> " << i << " " << j << endl;
                }
                else {
                    pair<int,int> temp = stack.pop();
                    prev_selectionX = temp.first;
                    prev_selectionY = temp.second;
                    //cout << "x , y is " << prev_selectionX << " " << prev_selectionY << endl;
                    pair<int,int> temp1 = stack.pop();
                    i = temp1.first;
                    j = temp1.second;
                }
               // cout << "i and j values are now back to " << i << ", " << j << endl;
               // cout << "currently looking for " << word[curr_char+1] << endl;
               // cout << matrix[i][j] << " and current letter is " << word[curr_char] << endl;
            }
            else {
                j++;
                //cout << "this \n";
            }
        }
        j = 0;
        i++;
        //cout << "going to next j value\n";
    }
    cout << "not found\n";
}

void read_part_1()
{
	//Read the number of commands to execute
    int n;
    cin >> n;
    Stack::Stack coList;
    // Initialize your stack here...
    
    char command1;
    int value1,value2;
    
    while (n--) 
    {
        cin >> command1;
        if (command1 == 'i')
        {
            cin >> value1 >> value2;
            pair <int,int> temp;
            temp = make_pair(value1,value2);
            coList.push(temp);
           // printf("Pushed values : %d, %d", temp.first, temp.second);
            // push the values in your stack here.
        }
        if (command1 == 'p')
        {
           // printf("Entering function pop\n");
            pair <int,int> temp1 = coList.pop();
            cout << temp1.first << " " << temp1.second << "\n";
            // Call Pop here, and print the values.
        }
    }
}

void read_part_2()
{
    int num_rows,num_cols;
    cin >> num_rows >> num_cols;
    cols = num_cols;
    char ** matrix;
    matrix = new char * [num_cols];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new char[num_cols];
    }
    int n = 0;
    while (n < num_rows) {
        char temp;
        for (int i = 0; i < num_cols; i++) {
            cin >> temp;
            matrix[n][i] = temp;
            //cout << matrix[n][i] << " ";
        }
        //cout << "\n";
        n++;
    }
    //cout << "finished matrix \n";
    //std::string word;
    //cin.sync();
    //cin.get();
    //std::cin >> word;
    //char mystring[100];
    string tofind;
    cin >> tofind;
   /* cout << "This word:" << tofind << "\n";
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        cout << "\n";
    }*/
    
    //cout << word[0] << "\n" << word.length();
    //cout << "finished reading. going to wordfinder now\n";
    wordFinder(matrix, num_rows, num_cols, tofind);
    
    
	//Read in the number of rows and cols in the puzzle

	//Declare the word search array

	//Fill in the array

	//Read in the word we're looking for
	
	//TODO: Part 1b: Run the word search
}

void read_part_3()
{
	//Read in the number of commands to execute
	int n;
    Deque::Deque queue;
	cin >> n;
	char command1,command2;
    int obj;
	while(n--)
	{
        cin >> command1;//>> command2;
        if (command1 == 'e') {
            cin >> command2;
            cin >> obj;
            if (command2 == 'b') {
                queue.enqueue_back(obj);
            }
            else {
                queue.enqueue_front(obj);
            }
        }
        else if (command1 == 'd') {
            cin >> command2;
            if (command2 == 'f') {
                cout << queue.dequeue_front() << "\n";
            }
            else {
                cout << queue.dequeue_back() << "\n";
            }
        }
        else if (command1 == 's') {
            queue.print();
        }
		// process command1 and command2
	}
}

void read_input()
{
	int project_part;
	//Read the first line of the test case
	cin >> project_part;
	
	switch(project_part)
	{
		case 1:
			read_part_1();
			break;
		case 2:
			read_part_2();
			break;
		case 3:
			read_part_3();
			break;
	}
}

int main()
{
	// Read in the test case
	read_input();
	return 0;
}










































