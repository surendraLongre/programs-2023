//insertionSort.cpp
#include<bits/stdc++.h>
#include "insertionSort.h"

InsertionSort::InsertionSort(int size, int  *temp_arr){
	this->size=0;
	arr=new int[size*2];
	insert(temp_arr[0]);

	for(int i=1; i!=size; i++){
		insert(temp_arr[i]);
	}
}

void InsertionSort::insert(int num){
	int temp_size=size;
	size++;
	while(temp_size!=0 && arr[temp_size-1]>num){
		arr[temp_size]=arr[temp_size-1];
		temp_size--;
	}
	arr[temp_size]=num;
}

void InsertionSort::print(){
	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;

}
