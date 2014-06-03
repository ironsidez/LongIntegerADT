

#include "doublylinkedlist.h"

// our data structure holds just the head and tail, now which point to our first and last nodes via ->next and ->prev
// this initializes these values, other operations are then our list ADT.


doublylinkedlist::doublylinkedlist()
{

	head = new struct Node;
	tail = new struct Node;

	/* since head and tail aren't proper nodes, just points of reference, I used a neg value.
	 we wont be dealing with negatives at this point otherwise so I can use it to tell when we are at
	 end of out list
	*/

	head->value = -1;
	head->prev = NULL;
	head->next = tail;

	tail->value = -1;
	tail->prev = head;
	tail->next = NULL;
		
}

doublylinkedlist::~doublylinkedlist()
{
	//allows us to delete our list, by destroying our only pointers to it.
	
	head = NULL;
	tail = NULL;
	delete head;
	delete tail;
}


struct Node* doublylinkedlist::createNode(int x) {

	//create our nodes

	struct Node* newnode = new struct Node;
	newnode->value = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}


//insert_Left
void doublylinkedlist::insertFront(int x) {



/*  Originally tried to use head and tail as first and last nodes, not just head->next and tail->prev as first and last.
	however this method kept giving me segmentation errors. I originally was using c, but I figured this would all be
	much easier with classes. It worked in c, had to switch to switch to current logic to get it to work in c++.

	struct Node* temp = new struct Node;
	struct Node* temp2 = head;
	struct Node* temp3 = tail;

	temp->value = x;
	if(temp2->value = -1) {
		head = temp;
		//tail = temp;
		return;
	}
	else if(temp3->value = -1){
		tail = temp2;
		tail->prev = head;
		head->next = tail;
		head = temp;
		return;
	}
	else{
		temp2->prev = temp;
		temp->next = temp2;
		head = temp;
	} 
*/
	
	struct Node* temp = createNode(x);
	struct Node* temp2 = head;

	insert(temp, temp2); //we insert temp after temp2

}

//insert_Right
void doublylinkedlist::insertBack(int x) {
	struct Node* temp = createNode(x);
	struct Node* temp2 = tail->prev;
	insert(temp, temp2); //we insert temp after temp2

}

void doublylinkedlist::insert(struct Node* temp, struct Node* temp2) {

	temp->prev = temp2; //temp2 is before new node
	temp->next = temp2->next; //the node after temp2 is now the node after new node
	temp2->next->prev = temp;  //the node after temp2 points back to new node, if first insert then this node is the tail.
	temp2->next = temp; //finally point temp2 to the new node

}

// is_last
int doublylinkedlist::isLast(struct Node* temp) {
	if(temp == tail->prev){
		return 1;
	}
	else{
		return 0;
	}
}

// get_Last
struct Node* doublylinkedlist::GetLast() {
	struct Node* temp = tail->prev;
	return temp; 
}

// is_First
int doublylinkedlist::isFirst(struct Node* temp) {
	if(temp = head->next){
		return 1;
	}
	else{
		return 0;
	}
}

// get_First
struct Node* doublylinkedlist::GetFirst() {
	struct Node* temp = head;
	return temp->next;
}

//  delete
void doublylinkedlist::deleteNode(struct Node* temp){
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
}


//  Next_Right
struct Node* doublylinkedlist::nextRight(struct Node* temp){
	temp = temp->next;
	return temp;
}

// Next_Left
struct Node* doublylinkedlist::nextLeft(struct Node* temp){
	temp = temp->prev;
	return temp;
}

void doublylinkedlist::clear()
{
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
}

/*
debugging code
void doublylinkedlist::Print() {
	struct Node* temp = head->next;
	int data;
	while(temp->value != -1) {
		data = temp->value;
		cout<<data<<endl;
		temp = temp->next;
	}	
}
*/

int doublylinkedlist::getValue(struct Node* temp) {
	int number = temp->value;
	return number;
}