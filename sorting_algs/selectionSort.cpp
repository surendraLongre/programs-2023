//bubbleShort.cpp
#include<bits/stdc++.h>
#include "selectionSort.h"

SelectionSort::SelectionSort(int size, int *temp_arr){
	this->size=size;
	arr=new int[size*2];
	arr=temp_arr;
}

void SelectionSort::print(){

	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void SelectionSort::shortArr(){
	int min_num_ind{},loop_index{};
	while(min_num_ind!=size-1){
		for(int i=loop_index+1; i<size; i++){
			if(arr[i]<arr[loop_index]){
				loop_index=i;
			}
		}

		if(min_num_ind!=loop_index)
			swap(min_num_ind, loop_index);
		min_num_ind++;
		loop_index=min_num_ind;

	}
}

void SelectionSort::swap(int min_num_ind, int loop_index){
	arr[min_num_ind]+=arr[loop_index];
	arr[loop_index]=arr[min_num_ind]-arr[loop_index];
	arr[min_num_ind]-=arr[loop_index];
}

void SelectionSort::insert(int num){
	int temp_size=size;
	size++;
	while(arr[temp_size-1]>num){
		arr[temp_size]=arr[temp_size-1];
		temp_size--;
	}
	arr[temp_size]=num;
}
