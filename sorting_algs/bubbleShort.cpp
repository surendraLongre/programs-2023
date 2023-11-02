//bubbleShort.cpp
#include<bits/stdc++.h>
#include "bubbleShort.h"

BubbleShort::BubbleShort(int size, int *temp_arr){
	this->size=size;
	arr=new int[size*2];
	arr=temp_arr;
}

void BubbleShort::print(){

	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void BubbleShort::shortArr(){
	bool term=true;
	while(term){
		term=false;
		for(int i=0; i!=size-1; i++){
			if(arr[i]>arr[i+1]){
				swap(i);
				term=true;
			}
		}
	}
}

void BubbleShort::swap(int index){
	arr[index]+=arr[index+1];
	arr[index+1]=arr[index]-arr[index+1];
	arr[index]-=arr[index+1];
}

void BubbleShort::insert(int num){
	int temp_size=size;
	size++;
	while(arr[temp_size-1]>num){
		arr[temp_size]=arr[temp_size-1];
		temp_size--;
	}
	arr[temp_size]=num;
}
