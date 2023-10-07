//charStack.cpp
#include "charStack.h"
#include<bits/stdc++.h>

Stack::Stack(){
	first=NULL;
	last=NULL;
}

void Stack::push(char num){
	Node *to_join=new Node;
	to_join->data=num;
	to_join->next=NULL;
	to_join->prev=NULL;
	if(first==NULL){
		last=first=to_join;
	} else{
		to_join->prev=last;
		last->next=to_join;
		last=to_join;
	}
	to_join=NULL;
	delete to_join;
}

void Stack::print(){
	Node *to_loop=first;
	while(to_loop!=NULL){
	       	std::cout<<to_loop->data;
		to_loop=to_loop->next;
	}
	std::cout<<std::endl;
	to_loop=NULL;
	delete to_loop;
}

char Stack::stackTop(){
	if(last==NULL) return '0';
	return last->data;
}

bool Stack::isEmpty(){
	if(first==NULL) return true;
	return false;
}

char Stack::pop() {
  if (last == NULL) {
    std::cout << "Stack is empty" << std::endl;
    return '\0';  // Return a default value or handle the empty stack case accordingly
  }

  char to_return = last->data;
  Node* to_delete = last;

  last = last->prev;

  if (last != NULL) {
    last->next = NULL;
  } else {
    // If the stack becomes empty after the pop, update 'first' pointer
    first = NULL;
  }

  delete to_delete;

  return to_return;
}

Node* Stack::getFirst(){
	return first;
}

Node* Stack::getLast(){
	return last;
}
