#include<bits/stdc++.h>
//not implementing unneccessary checks for example index out of range and so on,

class Node{
public:
	int data;
	Node *next=NULL;
};

class Stack:public Node{
	Node *first=new Node;
public:
	void push(int);
	int pop();
	void print();
	int peek(int); 
	int stackTop();
	int isEmpty();
};

void Stack::push(int num){
	Node *to_join=new Node;
	to_join->data=num;
	to_join->next=NULL;
	if(first==NULL){
		std::cout<<"created"<<std::endl;
		first=to_join;
	} else{
		to_join->next=first;
		first=to_join;
	}
	to_join=NULL;
	delete to_join;
}

void Stack::print(){
	Node *to_loop=first;
	while(to_loop->next!=NULL){
	       	std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
	std::cout<<std::endl;
	to_loop=NULL;
	delete to_loop;
}

int Stack::peek(int index){
	int counter=1;
	Node *to_loop=first;
	while(counter!=index){
		counter++;
		to_loop=to_loop->next;
	}
	int to_return=to_loop->data;
	to_loop=NULL;
	delete to_loop;
	return to_return;
}

int Stack::stackTop(){
	return first->data;
}

int Stack::isEmpty(){
	if(first->next==NULL) return true;
	return false;
}

int Stack::pop(){
	if(first->next==NULL) return -1;
	int to_return=first->data;
	Node *to_delete=first;
	first=first->next;
	delete to_delete;
	return to_return;
}

int main()
{
	Stack st1;
	st1.push(25);
	st1.push(30);
	st1.push(35);
	st1.push(15);
	std::cout<<st1.pop()<<std::endl;
	std::cout<<st1.pop()<<std::endl;
	std::cout<<st1.pop()<<std::endl;
	std::cout<<st1.pop()<<std::endl;
	st1.print();
}
