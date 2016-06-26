#include <iostream>

using namespace std;

class Deque
{
	public:
		Deque();
		void enqueue_front(int);
		void enqueue_back(int);
        void print();
		int dequeue_front();
		int dequeue_back();
		int get_array_size();
        int * array;
        int front, rear, count, length;
	private:
		void reallocate();
		bool is_full();
};