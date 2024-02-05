#ifndef QUEUE_H
#define QUEUE_H

class Node{
	public:
		int data;
		Node *next=nullptr;
};

class Queue:public Node{
	Node *first=new Node;
	Node *last=new Node;
	public:
		Queue();
		void push(int);
		int pop();
		void print();
		bool isEmpty();
};

#endif
