// C++ program to implement sorting a
// queue data structure
#include <iostream>
#include"MyStack.h"
#include"MyStack.cpp"
using namespace std;
// Queue elements after sortedIndex are
// already sorted. This function returns
// index of minimum element from front to
// sortedIndex
int minIndex(Queue<int>& q, int sortedIndex)
{
	int min_index = -1;
	int min_val = INT_MAX;
	int n = q.count + 1;
	for (int i = 0; i < n; i++)
	{
		int curr = q.Front();
		q.deQueue(); // This is dequeue() in C++ STL

		// we add the condition i <= sortedIndex
		// because we don't want to traverse
		// on the sorted part of the queue,
		// which is the right part.
		if (curr <= min_val && i <= sortedIndex)
		{
			min_index = i;
			min_val = curr;
		}
		q.enQueue(curr); // This is enqueue() in
					// C++ STL
	}
	return min_index;
}

// Moves given minimum element to rear of
// queue
void insertMinToRear(Queue<int>& q, int min_index)
{
	int count = 0;
	int min_val;
	int n = q.count + 1;
	for (int i = 0; i < n; i++)
	{
		int curr = q.Front();
		q.deQueue();
		if (i != min_index)
			q.enQueue(curr);
		else
			min_val = curr;
	}
	q.enQueue(min_val);
}

void sortQueue(Queue<int>& q)
{
	int count = q.count + 1;
	for (int i = 1; i <= count; i++)
	{
		int min_index = minIndex(q, count - i);
		insertMinToRear(q, min_index);
	}
}

// driver code
int main()
{
	Queue<int> q;
	q.enQueue(30);
	q.enQueue(11);
	q.enQueue(15);
	q.enQueue(4);

	/*
	// Sort queue
	sortQueue(q);

	// Print sorted queue
	*/
	while (q.isEmpty() == false)
	{
		cout << q.deQueue() << " ";
	}
	cout << endl;
	
	return 0;
}
s