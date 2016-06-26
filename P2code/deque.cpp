#include <iostream>
#include "deque.h"

using namespace std;

Deque::Deque()
{
    array = new int[10];
    front = -1;
    rear = -1;
    count = 0;
    length = 10;
	//TODO: Write the Deque constructor
	//NOTE: Start with an array of size 10!
}

void Deque::enqueue_front(int n)
{
    if (is_full()) {
        reallocate();
        enqueue_front(n);
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0) {
        front = length - 1;
    }
    else {
        front = front - 1;
    }
    array[front] = n;
    //cout << "enqueued front item: " << array[front] << " at position: " << front << "\n";
	//TODO: Front enqueue method
}

void Deque::enqueue_back(int n)
{
    if (is_full()) {
        cout << "is full, reallocating now \n";
        reallocate();
        //enqueue_back(n);
    }
    if (rear == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == length -1) {
        rear = 0;
    }
    else {
        rear++;
    }
    array[rear] = n;
   // cout << "enqueued back item: " << array[rear] << " at position: " << rear << "\n";
 	//TODO: Back enqueue
}

int Deque::dequeue_front()
{
    int temp;
    if (front == -1 && rear == -1) {
        cout << "Empty\n";
        exit(1);
    }
    temp = array[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        if (front == length -1) {
            front = 0;
        }
        else {
            front++;
        }
    }
    //cout << "deququed front item: " << temp <<"\n";
	//TODO: front dequeue
	return temp;
}

int Deque::dequeue_back()
{
   // cout << "entered function \n";
    int temp;
    if (front == -1) {
        cout <<"Empty\n";
        exit(1);
    }
    temp = array[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        if (rear == 0) {
            rear = length -1;
        }
        else {
            rear--;
        }
    }
    //cout << "deququed rear item: " << temp <<"\n";
	//TODO: back dequeue
	return temp;
}

void Deque::print()
{
    cout << length << "\n";
}

bool Deque::is_full()
{
    if ((front == 0 && rear == length -1) || (front == rear + 1)) {
        return true;
    }
    else {
        return false;
    }
	//TODO: Determine if you need to double the array
}

void Deque::reallocate()
{
    int temp[length * 2];
    for (int i = front; i <= rear; i++) {
        temp[i] = array[i];
        cout << temp[i] << " ";
    }
    cout << "\n";
    //delete array; -> not sure if this is required...
    array = temp;
    for (int i = 0; i < length*2; i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";
    length = length*2;
	//TODO: Correctly reallocate memory for the deque. Use the doubling strategy.
}