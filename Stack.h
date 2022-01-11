#pragma once

#include "StackNode.h"

class Stack {
private:
	StackNode * head;
public:
    // C'tor
	Stack();

    // Methods and Getters
	bool isEmpty() const;
	void makeEmpty();
	int Pop();
	void Push(int newElem);

    // D'tor
	~Stack();
};