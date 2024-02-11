#pragma once
#include <iostream>
#include "deque.h"
template <typename T>
class queue {
	deque<T> dq;
public:
	queue(int size = 1000) :dq(1000) {}
	void push(T data) {
		dq.pushLast(data);
	}
	T front() {
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