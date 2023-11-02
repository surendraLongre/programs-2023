//mergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H

class ListMerge{ //merging two arrays into once
	int *arr;
	int size;
public:
	void merge(int *, int, int*, int); //parameters: (list1, size1, list2, size2)
	void print();
};

class ArrayMerge{ //from just one list only which has two parts and both are sorted: {2,5,8,12,3,4,9,16}
	int *arr;
	int size;
public:
	void merge(int *, int,int,int);
	~ArrayMerge();
	void iMergeSort(int *, int);
	void recurSort(int*,int,int);
	void print();
};

#endif
