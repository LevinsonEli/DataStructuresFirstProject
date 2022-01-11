
#include "List.h"

List::List(int size) {
	if (size <= 0) {
		this->data = nullptr;
		this->maxSize = 0;
		this->curSize = 0;
	}
	else {
		this->maxSize = size;
		this->data = new int[this->maxSize];
		this->curSize = 0;
		this->head = size / 2 - 1;
		this->tail = this->head + 1;
	}
}
void List::addToHead(int newElem) {
	if (!this->isFull()) {
		this->head++;
		if (this->head == this->maxSize)
			this->head = 0;
		this->curSize++;
		this->data[this->head] = newElem;
	}
}
void List::addToTail(int newElem) {
	if (!this->isFull()) {
		this->tail--;
		if (this->tail == -1)
			this->tail = this->maxSize - 1;
		this->curSize++;
		this->data[this->tail] = newElem;
	}
}
int List::removeFromHead() {
	if (!this->isEmpty()) {
		int removedFromHead = this->data[this->head];
		this->head--;
		if (this->head == -1)
			this->head = this->maxSize - 1;
		this->curSize--;
		return removedFromHead;
	}
	return -1;
}
int List::removeFromTail() {
	if (!this->isEmpty()) {
		int removedFromTail = this->data[this->tail];
		this->tail++;
		if (this->tail == this->maxSize)
			this->tail = 0;
		this->curSize--;
		return removedFromTail;
	}
	return -1;
}
bool List::isEmpty() const {
	return this->curSize == 0;
}
bool List::isFull() const {
	return this->curSize == this->maxSize;
}

List::~List() {
	delete [] this->data;
}