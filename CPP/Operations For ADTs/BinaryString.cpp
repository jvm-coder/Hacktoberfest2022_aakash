#pragma once
/*
Stack ADT:
Individual items can be added and stored using a push operation
Individual items can be removed and extracted using a push operation
*/

template<class T>
class MyStack {
private:
	int size;
	int top;
	T* stack;
public:
	MyStack();
	MyStack(int);
	void Push(T x);
	T Pop();
	T Peek();
	bool isFull();
	bool isEmpty();
	void resize();
	~MyStack();
};

#include<iostream>
using namespace std;


template<class T>
MyStack<T>::MyStack()
{
	size = 10;
	top = -1;
	stack = new T[size];
}

template<class T>
MyStack<T>::MyStack(int s)
{
	size = s;
	top = -1;
	stack = new T[size];
}

template<class T>
void MyStack<T>::Push(T x)
{
	/*
	The function will add a receieved item to the stack
	:param s: The item recieved
	:return: True if Valid else false
	*/

	if (isFull())
		resize();

	stack[++top] = x;

}

template<class T>
T MyStack<T>::Pop()
{
	/*
	The function remove the top item from the stack
	:return: Removed item
	*/

	if (isEmpty())
		resize();

	else if (top + 1 <= size / 4) {
		resize();
		return stack[top--];
	}

	else return stack[top--];
}

template<class T>
T MyStack<T>::Peek()
{
	/*
	The function show the top item
	:return: Top element/item
	*/

	return stack[top];
}

template<class T>
bool MyStack<T>::isFull()
{
	/*
	The function will tell if the stack is full or not
	:return: True if full else false
	*/

	return top == size - 1;
}

template<class T>
bool MyStack<T>::isEmpty()
{
	/*
	The function will tell if the stack is empty or not
	:return: True if empty else false
	*/

	return top == -1;
}

template<class T>
void MyStack<T>::resize()
{
	/*
	The function will resize the stack if stack if full or 3/4th of stack is empty
	Size is increased by 2 times if it is full
	Size is decreased by 2 times if it's  3/4th of stack is empty
	*/

	if (isFull()) {
		size *= 2;
	}

	else if (top + 1 <= size / 4) {
		size = ceil(size / 2);
	}

	if (size == 0)
		size = 2;

	T* stack2 = new T[size];

	for (int i = 0; i <= top; i++) {
		stack2[i] = stack[i];
	}

	if (size > 0)
		delete[] stack;
	stack = stack2;

}

template<class T>
MyStack<T>::~MyStack()
{
	if (size > 0)
		delete[] stack;
}






int main() {


	MyStack<char> S;
	string s;
	cin >> s;
	int count0 = 0;
	int count1 = 0;
	bool perf = false;
	int n = 0;
	cin >> n;
	while (n--) {
		while (1) {
			count0 = 0;
			count1 = 0;
			for (int i = 0; i < s.length(); i++) {

				S.Push(s[i]);
				if (s[i] == '1') {
					count1++;
					count0 = 0;
				}
				else {
					count0++;
					count1 = 0;
				}

				if (count1 % 2 == 0 && count1 != 0) {
					count0 = 0;
					S.Pop();
					S.Pop();
					perf = true;
				}

				else if (count0 % 2 == 0 && count0 != 0) {
					count1 = 0;
					S.Pop();
					S.Pop();
					perf = true;
				}

				if (s.length() == 2) {
					if (count1 == 2)
						s = "";

					if (count0 == 2)
						s = "";

				}
			}

			if (perf == false)
				break;

			else perf = false;

			if (!(S.isEmpty()))
				s = S.Pop();
			while (!(S.isEmpty()))
				s += S.Pop();
		}

		if (s.length() == 0)
			cout << "KHALI" << endl;
		else
			cout << s << endl;

	}

	return 0;
}