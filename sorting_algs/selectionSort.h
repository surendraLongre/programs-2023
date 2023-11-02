//selectionSort.h
//in this method we first choose an index and then finding the elements suitable for that position and making sure the index gets the element it deserves
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

class SelectionSort{
	int *arr;
	int size{};

public:
	SelectionSort(int, int *);
	void print();
	void shortArr();
	void swap(int,int);
	void insert(int);
};

#endif
