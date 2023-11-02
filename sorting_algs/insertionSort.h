//insertionSort.h
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

class InsertionSort{
	int *arr;
	int size{};
public:
	InsertionSort(int,int*);
	void print();
	void shortArr();
	void swap(int);
	void insert(int);
};

#endif
