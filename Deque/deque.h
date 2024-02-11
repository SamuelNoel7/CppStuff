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
		this->next = nullptr;
		this->prev = nullptr;
	}
};
template <typename T>
class deque {
	Node<T>* m_front;
	Node<T>* m_last;
	unsigned int m_maxSize;
	unsigned int m_size = 0;
public:
	deque(unsigned int m_maxSize = 1000) {
		this->m_maxSize = m_maxSize;
		m_front = m_last = nullptr;
	}
	bool isFull() {
		return m_size == m_maxSize;
	}
	bool isEmpty() {
		return m_size == 0;
	}
	void pushFront(T value) {
		try {
			if (isFull()) {
				throw overflow_error("Overflow Error, unable to insert the element");
			}
			Node<T>* temp = new Node<T>(value);
			if (isEmpty()) {
				m_front = temp;
				m_last = temp;
			}
			else {
				temp->next = m_front;
				m_front->prev = temp;
				m_front = temp;
			}
			m_size++;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void pushLast(T value) {
		try {
			if (isFull()) {
				throw overflow_error("Overflow Error, unable to insert the element");
			}
			Node<T>* temp = new Node<T>(value);
			if (isEmpty()) {
				m_front = temp;
				m_last = temp;
			}
			else {
				temp->prev = m_last;
				m_last->next = temp;
				m_last = temp;
			}
			m_size++;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void popFront() {
		try {
			if (isEmpty()) {
				throw underflow_error("Underflow Error, unable to pop the element");
			}
			Node<T>* temp = m_front;
			if (m_front == m_last) {
				m_front = m_last = nullptr;
				delete temp;
			}
			else {
				m_front = m_front->next;
				m_front->prev = nullptr;
				temp->next = nullptr;
				delete temp;
			}
			m_size--;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	void popLast() {
		try {
			if (isEmpty()) {
				throw underflow_error("Underflow Error, unable to pop the element");
			}
			Node<T>* temp = m_last;
			if (m_front == m_last) {
				m_front = m_last = nullptr;
				delete temp;
			}
			else {
				m_last = m_last->prev;
				temp->prev = nullptr;
				m_last->next = nullptr;
				delete temp;
			}
			m_size--;
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	int size() {
		return m_size;
	}
	void print() {
		Node<T>* temp = m_front;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	T getFront() {
		try {
			if (m_size > 0)
				return m_front->data;
			else
				throw range_error("The data structure is empty");
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
	T getLast() {
		try {
			if (m_size > 0)
				return m_last->data;
			else
				throw range_error("The data structure is empty");
		}
		catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
		}
	}
};
