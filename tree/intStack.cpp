//intIntStack.cpp
#include "intStack.h"
#include<bits/stdc++.h>

void IntStack::enqueue(Node *x)
{
	if(rear==size-1)
		printf("IntStack Full\n");
	else
	{
		rear++;
		Q[rear]=x;
	}
}

Node *IntStack::dequeue() {
	Node *x=NULL;
	if(front==rear)
		printf("IntStack is Empty\n");
	else
	{
		x=Q[front+1];
		front++;
	}
	return x;
}
