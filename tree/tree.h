//tree.h
#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "intStack.h"

class Tree{
	IntStack *queue=new IntStack;
	Node *root=new Node;
public:
	Tree();
	void preOrder(Node *);
	Node * getRoot();
	int nodeCount(Node *);
	int height(Node *);
	int nodeCountDegree0(Node *);
	int nodeCountDegree1(Node *);
	int nodeCountDegree2(Node *);
	bool isPresent(int);
	void insert(int);
};

#endif
