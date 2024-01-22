#ifndef LIST_H
#define LIST_H

class Node {
	public:
		int data;
		Node *next=nullptr;
};

class List:public Node{
	Node *first = new Node;
	public:
		List();
		void push(int);
		bool search(int);
		int delete_node();
		void print();
};

#endif
