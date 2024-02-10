#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node<T>(T data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};
template <typename T>
class deque {
	Node<T>* front;
	Node<T>* last;
	unsigned int max_size;
	unsigned int size = 0;
public:
	deque(unsigned int max_size = 100) {
		this->max_size = max_size;
		front = last = NULL;
	}
	bool isFull() {
		return size == max_size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void pushFront(T data) {
		try {
			if (isFull()) {
				throw overflow_error("Deque is full");
			}
			Node<T>* temp = new Node<T>(data);
			if (isEmpty()) {
				front = temp;
				last = temp;
			}
			else {
				temp->next = front;
				front->prev = temp;
				front = temp;
			}
			size++;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void pushLast(T data) {
		try {
			if (isFull()) {
				throw overflow_error("Deque is full");
			}
			Node<T>* temp = new Node<T>(data);
			if (isEmpty()) {
				front = temp;
				last = temp;
			}
			else {
				temp->prev = last;
				last->next = temp;
				last = temp;
			}
			size++;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void popFront() {
		try {
			if (isEmpty()) {
				throw underflow_error("Deque is empty");
			}
			Node<T>* temp = front;
			if (front == last) {
				front = last = NULL;
				delete temp;
			}
			else {
				front = front->next;
				front->prev = NULL;
				temp->next = NULL;
				delete temp;
			}
			size--;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void popLast() {
		try {
			if (isEmpty()) {
				throw underflow_error("Deque is empty");
			}
			Node<T>* temp = last;
			if (front == last) {
				front = last = NULL;
				delete temp;
			}
			else {
				last = last->prev;
				temp->prev = NULL;
				last->next = NULL;
				delete temp;
			}
			size--;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	int get_size() {
		return size;
	}
	void print() {
		Node<T>* temp = front;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	T getFront() {
		return front->data;
	}
	T getLast() {
		return last->data;
	}
};
