/*
	Reason for doubly linked list is that when you popBack you 
	need to traverse the entire list if it was singly linked list
*/

#include<iostream>
#include<string>
#include "stack.h"
#include "queue.h"
using namespace std;



int main() {
	stack<int> s(10);
	cout << s.empty() << endl;
	s.push(10);
	s.push(12);
	s.push(13);
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.top() << endl;
	s.pop();
	s.pop();
	return 0;
}