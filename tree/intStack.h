//intIntStack.h
#ifndef INTSTACK_H
#define INTSTACK_H
#include "node.h"

class IntStack {
	private:
		int front;
		int rear;
		int size;
		Node **Q;
	public:
		IntStack(){
			front=rear=-1;size=10;Q=new Node*[size];
		}
		IntStack(int size){
			front=rear=-1;this->size=size;
			Q=new Node*[size];
		}
		void enqueue(Node *x);
		Node *dequeue();
		int isEmpty(){ return front==rear;}
};

#endif
