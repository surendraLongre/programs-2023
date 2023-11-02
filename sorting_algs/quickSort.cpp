//quickSort.cpp
#include<bits/stdc++.h>
#include "quickSort.h"

QuickSort::QuickSort(int size, int *temp_arr){
	this->size=size;
	arr=new int[size*2];
	arr=temp_arr;
}

void QuickSort::print(){

	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void QuickSort::shortArr(int l, int h){
	int j{};
	if(l<h){
		j=partition(l,h);
		shortArr(l,j);
		shortArr(j+1,h);
	}
}

int QuickSort::partition(int l, int h){
	int pivot=arr[l];
	int i=l; //look for elements greater than pivot
	int j=h; //look for elements smaller than pivot

	do{
		do{i++;}while(arr[i]<=pivot && i<h);
		std::cout<<"i: "<<i<<std::endl;
		do{j--;}while(arr[j]>pivot && j>l);
		std::cout<<"j: "<<j<<std::endl;
		if(i<j)
			swap(i,j);
	} while(j>i);
		swap(l,j);
		return j;
}

void QuickSort::swap(int i1, int i2){
	int temp=arr[i1];
	arr[i1]=arr[i2];
	arr[i2]=temp;
}

void QuickSort::insert(int num){
	int temp_size=size;
	size++;
	while(arr[temp_size-1]>num){
		arr[temp_size]=arr[temp_size-1];
		temp_size--;
	}
	arr[temp_size]=num;
}
