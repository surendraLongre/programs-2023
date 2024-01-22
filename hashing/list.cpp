#include<bits/stdc++.h>
#include "list.h"

List::List(){
	first=NULL;
}

void List::push(int num){
	std::cout<<"pushing some"<<std::endl;
	Node *to_join=new Node;
	Node *traverse=first;
	to_join->data=num;
	to_join->next=NULL;

	if(first==NULL)
		first=to_join;
	else if(num<first->data){
		std::cout<<"changed first"<<std::endl;
		to_join->next=first;
		first=to_join;
	} else {
		std::cout<<"inside the while loop"<<std::endl;
//		while(traverse!=NULL && num>traverse->next->data){
		while(traverse->next != nullptr && num > traverse->next->data){
			std::cout<<"inside the while loop"<<std::endl;
			traverse=traverse->next;
		}
		std::cout<<"out of while loop"<<std::endl;
		to_join->next=traverse->next;
		traverse->next=to_join;
	}
//	delete traverse;
//	delete to_join;
}

bool List::search(int num){
	Node *head=first;
	while(head!=nullptr){
		if(num==head->data)
			return true;
		head=head->next;
	}
//delete head;
	return false;
}

void List::print(){
	std::cout<<"printing some"<<std::endl;
	Node *head=first;
	while(head!=NULL){
		std::cout<<head->data<<" ";
		head=head->next;
	}
//delete head;
}
