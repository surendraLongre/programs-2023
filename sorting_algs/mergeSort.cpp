//mergeSort.cpp
#include<bits/stdc++.h>
#include "mergeSort.h"

void ListMerge::merge(int* arr1, int size1, int* arr2, int size2){
	size=size1+size2;
	arr=new int[size];
	int i1{},i2{};
	for(int k=0; k!=size; k++){
		if(i1!=size1 && i2!=size2){
			if(arr1[i1]<arr2[i2])
				arr[k]=arr1[i1++];
			else
				arr[k]=arr2[i2++];
		} else if(i1!=size1 && i2==size2)
			arr[k]=arr1[i1++];
		else 
			arr[k]=arr2[i2++];
	}
}

void ListMerge::print(){
	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void ArrayMerge::iMergeSort(int arr[],int n){
	int p{}, i{}, l{}, mid{}, h{};

	for(p=2; p<=n; p*=2){
		for(i=0; i+p-1<n; i+=p){
			l=i;
			h=i+p-1;
			mid=floor((l+h)/2);
			merge(arr, l, mid, h);
		}
	}
	if(p/2<n)
		merge(arr, 0, p/2-1,n-1);
}

void ArrayMerge::recurSort(int arr[], int l, int h){
	if(l<h){
		int mid=floor((l+h)/2);
		recurSort(arr, l,mid);
		recurSort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}
}

//void ArrayMerge::merge(int *temp_arr, int l, int mid,  int h){
//	size=h;
//	arr=new int[size];
//	int i1{}, i2=mid;
//	for(int k=l; k!=size; k++){
//		if(i1!=mid && i2!=h){
//			if(temp_arr[i1]<temp_arr[i2])
//				arr[k]=temp_arr[i1++];
//			else
//				arr[k]=temp_arr[i2++];
//		} else if(i1!=mid && i2==h)
//			arr[k]=temp_arr[i1++];
//		else 
//			arr[k]=temp_arr[i2++];
//	}
//
//	for(int k=l; k!=h; k++){
//		temp_arr[k]=arr[k];
//	}
//}
void ArrayMerge::merge(int *temp_arr, int l, int mid, int h) {
	std::cout<<"low: "<<l<<std::endl
		<<"high: "<<h<<std::endl
		<<"mid: "<<mid<<std::endl;
	int size = h - l + 1;
	arr = new int[size];
	int i1 = l;
	int i2 = mid + 1;

	for (int k = 0; k < size; k++) {
		if (i1 <= mid && (i2>h || temp_arr[i1]<temp_arr[i2] )) 
			arr[k] = temp_arr[i1++];
		else
			arr[k] = temp_arr[i2++];
	}
	for (int k = 0; k < size; k++) {
		temp_arr[l + k] = arr[k];
	}
	std::cout<<"size: "<<size<<std::endl;
}


void ArrayMerge::print(){
	for(int i=0; i!=size; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

ArrayMerge::~ArrayMerge(){
	delete []arr;
}
