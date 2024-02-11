#pragma once
#include<iostream>
#include "deque.h"
using namespace std;
template <typename T>
class stack {
	deque<T> dq;
public:
	stack(int size = 1000) :dq(size) {}
	void push(T data) {
		dq.pushFront(data);
	}
	T top() {
		return dq.getFront();
	}
	bool empty() {
		return dq.isEmpty();
	}
	int size() {
		return dq.size();
	}
	void pop() {
		dq.popFront();
	}
};