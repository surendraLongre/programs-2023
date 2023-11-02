//countSort.cpp
#include<bits/stdc++.h>
#include "countSort.h"

void CountSort::sortArray(int *temp_arr, int n){
	for(int i=0; i!=n; i++){
		size=std::max(size,temp_arr[i]);
	}
	arr=new int[size+1];

	for(int i=0; i!=n; i++)
		arr[i]=0;
	
	for(int i=0; i!=n; i++)
		arr[temp_arr[i]]++;

	for(int i=0,j=0; i!=size+1; i++){
		while(arr[i]-- !=0)
			temp_arr[j++]=i;
	}
}

CountSort::~CountSort(){
	delete []arr;
}
