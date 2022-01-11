#pragma once

class List {
private:
	int * data;
	int maxSize;
	int curSize;
	int tail;
	int head;
public:
    // C'tor
	List(int size = 0);

    // Getters and Setters
	void addToHead(int newElem = -1);
	void addToTail(int newElem = -1);
	int removeFromHead();
	int removeFromTail();
	bool isEmpty() const;
	bool isFull() const;
    
    // D'tor
	~List();
};