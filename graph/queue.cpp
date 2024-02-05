#include<bits/stdc++.h>
#include "queue.h"

Queue::Queue(){
	first=NULL;
}

void Queue::push(int num){
	Node *to_push=new Node;
	to_push->data=num;
	to_push->next=nullptr;
	if(first==NULL){
//		std::cout<<"first is last"<<std::endl;
		first=last=to_push;
	}
	else{
		last->next=to_push;
		last=to_push;
	}
	to_push=NULL;
	delete to_push;
}

int Queue::pop(){
	if(isEmpty()){
		std::cout<<"the queue is empty"<<std::endl;
		return 0;
	}
	int to_return=first->data;
	Node *to_delete=first;
	if(first->next==nullptr){
		first==NULL;
	}
	if(first!=NULL)
		first=first->next;
	delete to_delete;
	return to_return;
}

void Queue::print(){
	Node *to_traverse=first;
	while(to_traverse!=NULL){
		std::cout<<to_traverse->data<<" ";
		to_traverse=to_traverse->next;
	}
}

bool Queue::isEmpty(){
	if(first==NULL)
		return true;
	return false;
}
