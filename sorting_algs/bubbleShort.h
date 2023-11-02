//bubbleShort.h
#ifndef BUBBLESHORT_H
#define BUBBLESHORT_H

class BubbleShort{
	int *arr;
	int size{};

public:
	BubbleShort(int, int *);
	void print();
	void shortArr();
	void swap(int);
	void insert(int);
};

#endif
