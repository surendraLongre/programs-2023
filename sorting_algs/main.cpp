#include<bits/stdc++.h>
#include "bubbleShort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "countSort.h"

int main()
{
	int arr[]={20,25,9,5,6,6};

	CountSort b1;
	b1.sortArray(arr,6);
	//for(int i=0; i!=5; i++){
	//	std::cout<<arr[i]<<" ";
	//}

	for(int i=0; i!=6; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
