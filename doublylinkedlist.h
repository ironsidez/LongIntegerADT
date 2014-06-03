#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

	
	struct Node {

	int value;
	struct Node* prev;
	struct Node* next;
	
};

class doublylinkedlist
{
public:
	doublylinkedlist();
	~doublylinkedlist();
	struct Node* head;
	struct Node* tail;
	//struct Node* newnode;
	struct Node* createNode(int x);
	void insertFront(int x);
	void insertBack(int x);
	void insert(struct Node* temp, struct Node* temp2);
	struct Node* GetFirst();
	int isFirst(struct Node* temp);
	struct Node* GetLast();
	int isLast(struct Node* temp);
	struct Node* nextRight(struct Node* temp);
	void deleteNode(struct Node* temp);
	struct Node* nextLeft(struct Node* temp);
	int getValue(struct Node* temp);
	//void Print();
	void clear();

};	
	

#endif