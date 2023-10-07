//intIntStack.cpp
#include "intStack.h"
#include<bits/stdc++.h>

IntStack::IntStack(){
	first=NULL;
	last=NULL;
}

void IntStack::push(int num){
	IntNode *to_join=new IntNode;
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

void IntStack::print(){
	IntNode *to_loop=first;
	while(to_loop!=NULL){
	       	std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
	std::cout<<std::endl;
	to_loop=NULL;
	delete to_loop;
}

int IntStack::stackTop(){
	if(last==NULL) return '0';
	return last->data;
}

bool IntStack::isEmpty(){
	if(first==NULL) return true;
	return false;
}

int IntStack::pop() {
  if (last == NULL) {
    std::cout << "IntStack is empty" << std::endl;
    return '\0';  // Return a default value or handle the empty stack case accordingly
  }

  int to_return = last->data;
  IntNode* to_delete = last;

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

int IntStack::evaluated(){
	return first->data;
}

