#include "Stack.h"

Stack::Stack() {
	this->head = nullptr;
}

bool Stack::isEmpty() const {
	return this->head == nullptr;
}
void Stack::makeEmpty() {
    if (!this->isEmpty()) {
        this->~Stack();
    }
    this->head = nullptr;
}
int Stack::Pop() {
	if (!this->isEmpty()) {
		StackNode * popedElement = this->head;
		this->head = this->head->getNext();
		return popedElement->getData();
	}
	return -1;  // default return value
}
void Stack::Push(int newElem) {
	StackNode * newNode = new StackNode(newElem, this->head);
	this->head = newNode;
}

Stack::~Stack() {
	while (this->head != nullptr) {
		StackNode * nodeToDelete = this->head;
		this->head = this->head->getNext();
		delete nodeToDelete;
	}
}