//quickSort.h
//here we take a element and then by interchanging we make sure that 
//on left: all elements are smaller than the pivotal element, and
// on right: all elements are larger than the pivotal element.
#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort{
	int *arr;
	int size{};

public:
	QuickSort(int, int *);
	void print();
	void shortArr(int,int);
	int partition(int,int);
	void swap(int,int);
	void insert(int);
};

#endif
