//intIntStack.h
#ifndef INTSTACK_H
#define INTSTACK_H

class IntNode{
public:
	int data;
	IntNode *next=nullptr;
	IntNode *prev=nullptr;
};

class IntStack:public IntNode{
	IntNode *first=new IntNode;
	IntNode *last= new IntNode;
public:
	IntStack();
	void push(int);
	int pop();
	void print();
	int peek(int); 
	int stackTop();
	bool isEmpty();
	int evaluated();
};

#endif
