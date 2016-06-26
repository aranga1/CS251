 #include "stack.h"
 #include <utility>


 Stack::Stack()
 {
     top = NULL;
	 //TODO: Write the constructor
 }
 
 void Stack::push(pair<int,int> coordinates)
 {
     struct node * temp = new node;
     temp->points = coordinates;
    // cout << "stored values: " << temp->points.first << " " << temp->points.second;
     temp->next = NULL;
     if (top != NULL) {
         temp->next = top;
     }
     top = temp;
    // cout << "top instantiated values: " << top->points.first << " " << top->points.second;
	 //TODO: Write the push method
 }
 
 pair<int,int> Stack::pop()
 {
     pair<int,int> reqPts;
     //cout << "Pair instantiated \n";
     struct node *temp;
     //cout << "node instantiated \n";
     if (top == NULL) {
         cout << "Empty\n";
         exit(1);
     }
    // cout << "top points are : " << top->points.first << " " << top->points.second;
     temp = top;
     reqPts = top->points;
     //cout << "reqPoints referred: points are: " << reqPts.first << " " << reqPts.second;
     top = top->next;
	 //TODO: Write the pop method
	 return reqPts;
 }

void Stack::print() {
    if (top != NULL) {
        struct node * temp = top;
        printReverse(temp);
    }
    else {
        printReverse(NULL);
    }
}

void Stack::printReverse(struct node* head) {
    if (head == NULL) {
        return;
    }
    
    printReverse(head->next);
    
    printf("%d %d\n", head->points.first, head->points.second);
}





























