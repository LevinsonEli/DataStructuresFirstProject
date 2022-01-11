#pragma once

class StackNode {
private:
	int data;
	StackNode * next;
public:
    // C'tor
	StackNode(int data = -1, StackNode * next = nullptr);

    // Getters
	int getData() const;
	StackNode * getNext() const;
};