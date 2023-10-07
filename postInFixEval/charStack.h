//charStack.h
#ifndef CHARSTACK_H
#define CHARSTACK_H

class Node{
public:
	char data;
	Node *next=nullptr;
	Node *prev=nullptr;
};

class Stack:public Node{
	Node *first=new Node;
	Node *last= new Node;
public:
	Stack();
	void push(char);
	char pop();
	void print();
	int peek(int); 
	char stackTop();
	bool isEmpty();
	Node* getFirst();
	Node* getLast();
};

#endif
