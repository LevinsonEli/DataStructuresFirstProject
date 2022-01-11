
#include "StackNode.h"

StackNode::StackNode(int data, StackNode * next) {
	this->data = data;
	this->next = next;
}
int StackNode::getData() const {
	return this->data;
}
StackNode * StackNode::getNext() const {
	return this->next;
}