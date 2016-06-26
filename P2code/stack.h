 #include <iostream>
 #include <utility>
 
 using namespace std;

struct node
{
    pair<int,int> points;
    struct node *next;
};
 class Stack
 {
	 public:
        struct node* top;
		Stack();
		void push(pair<int,int>);
		pair<int,int> pop();
        void print();
        void printReverse(struct node* head);
 };