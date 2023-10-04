#include<bits/stdc++.h>
using namespace std;

//for most cases the code works perfectly
//there are some bugs in appending and inserting
//help me if you find them and solved also

class Node{
	public:
	int data;
	Node *next=NULL;
};

class DoublyNode{
	public:
	DoublyNode *prev=NULL;
	DoublyNode *next=NULL; 
	int data;
};

class LinkedList:public Node{
	Node *first=new Node;
	Node *last=first;
	public:
		LinkedList();
		void create(int *, int);
		void print();
		void insert(int,int);
		void append(int);
		int delete_first();
		int delete_at(int);
		void reverse();
		void reverseUsingRecursion(Node*, Node*);
};

class DoublyLinkedList:public DoublyNode{
	DoublyNode *first=new DoublyNode;
	DoublyNode *last=new DoublyNode;
	public:
		void create(int *, int);
		void print();
};

void DoublyLinkedList::create(int *arr, int num){
	DoublyNode *to_join=new DoublyNode;
	to_join->data=arr[0];
	to_join->next=NULL;
	to_join->prev=NULL;
	first=to_join;
	last=first;

	for(int i=1; i!=num; i++){
		DoublyNode *t=new DoublyNode;
		t->data=arr[i];
		t->next=NULL;
		t->prev=to_join;
		to_join->next=t;
		to_join=t;
		last=to_join;
	}
	std::cout<<"created doubly linkedlist"<<std::endl;
}

void DoublyLinkedList::print(){
	DoublyNode *to_loop=last;
	do{
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->prev;
	} while(to_loop!=NULL);
	std::cout<<std::endl;

}

class CircularLinkedList{
	Node *first=new Node;
	public:
		void print();
		void create(int *, int);
};

void CircularLinkedList::create(int *arr, int num){
	Node *to_join=new Node;
	to_join->data=arr[0];
	to_join->next=NULL;
	first=to_join;

	for(int i=1; i!=num; i++){
		Node *t=new Node;
		t->data=arr[i];
		t->next=NULL;
		to_join->next=t;
		to_join=t;
	}
	to_join->next=first;
	std::cout<<"created circular linked list"<<std::endl;
}

void CircularLinkedList::print(){
	Node *to_loop=first;
	do{
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	} while(to_loop!=first);
	std::cout<<std::endl;
}

LinkedList::LinkedList(){
}


void LinkedList::create(int *arr, int n){
	Node *t;
	first->data=arr[0];
	first->next=NULL;
	last=first;

	for(int i=1; i!=n; i++){
		t=new Node;
		t->data=arr[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void LinkedList::print(){
	Node *to_print=first;
	while(to_print!=NULL){
		std::cout<<to_print->data<<" ";
		to_print=to_print->next;
	}
	to_print=NULL;
	delete to_print;
	std::cout<<std::endl;
}

void LinkedList::insert(int index, int num){
	Node *to_join=new Node;
	to_join->data=num;

	if(index==0){
		to_join->next=first;
		first=to_join;
		to_join=NULL;
		delete to_join;
		return;
	}

	Node *head=first;

	for(int i=0; i<index-1; i++){
		head=head->next;
	}
	to_join->next=head->next;
	head->next=to_join;

	head=NULL;
	to_join=NULL;

	delete head;
	delete to_join;
}

void LinkedList::append(int num){
	Node *to_join=new Node;
	to_join->data=num;
	to_join->next=NULL;

	if(first->data==0){
		std::cout<<"creating"<<std::endl;
		first=last=to_join;
	}
	last->next=to_join;
	last=to_join;

	to_join=NULL;
	delete to_join;
}

int LinkedList::delete_first(){
	Node *to_delete=first;
	int to_return=to_delete->data;
	first=first->next;
	delete to_delete;
	return to_return;
}

int LinkedList::delete_at(int index){
	if(index==0) return delete_first();
	Node *head=first;
	for(int i=0; i<index-1; i++){
		head=head->next;
	}
	Node *tail=head->next;
	Node *to_delete=tail;
	int to_return=tail->data;
	tail=tail->next;
	head->next=tail;

	delete to_delete;
	return to_return;

}

void LinkedList::reverse(){
	Node *f1=first;
	last=first;
	reverseUsingRecursion(f1,f1->next);
}

void LinkedList::reverseUsingRecursion(Node *q, Node *p){
	if(p!=NULL){
		reverseUsingRecursion(p, p->next);
		p->next=q;
	} else{
		first->next=NULL;
		first=q;
	}
}

int main()
{
	int A[]{10,20,30,90};
	DoublyLinkedList n1;
	n1.create(A, sizeof(A)/sizeof(A[0]));
	n1.print();
	
}
