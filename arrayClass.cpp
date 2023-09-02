#include<bits/stdc++.h>
using namespace std;

class Array
{
	int *arr;
	int size{};
	static int current_size;

public:
	Array();
	Array(int *);
	void arr_size(int);

	//get the array size
	int get_size(){return current_size;};
	//initialize array with array size
	void init_arr();

	//insert a number, at index
	void insert(int, int);

	//print numbers
	void print_arr();

	//delete elements at index
	void delete_ele(int);

	//write binary searching algorithm which returns the index
	//
	int binSearch(int , int , int);
};

int Array::current_size=0;

Array::Array(){
};

Array::Array(int *arr){
	this->arr=arr;
}

void Array::arr_size(int size){
	this->size=size;
}

void Array::init_arr(){
	arr=new int[size];
	cout<<"initialized array of size "<<size<<endl;
}

void Array::insert(int num, int index=current_size){
	if(current_size>=size){
		cout<<"array size exceeded"<<endl;
	}
	for(int i=current_size; i!=index; i--){
		arr[i]=arr[i-1];
	}
	arr[index]=num;
	current_size++;
}

void Array::print_arr(){
	for(int i=0; i!=current_size; i++) cout<<arr[i]<<" ";
}

void Array::delete_ele(int index){
	//0<=index<current_size
	if(index<0 || index>=current_size) {
		cout<<"index out of range"<<endl; 
		return;
	}
	for(int i=index; i!=current_size-1; i++){
		arr[i]=arr[i+1];
	}
	current_size--;
	arr[current_size]=0;
}

int Array::binSearch(int low, int high, int num){
	cout<<"searching the elemetn: "<<num<<endl;
	while(low<=high){
		int mid=(low+high)/2;
		cout<<"mid: "<<mid<<endl;
		if(arr[mid]==num)return mid;

		if(num>arr[mid]) low=mid+1;
		if(num<arr[mid]) high=mid-1;
	}
	return -1;
}

int main()
{
	Array arr1;
	int size{};
	cin>>size;
	arr1.arr_size(size);
	arr1.init_arr();

	cout<<"how many numbers you want to enter? "<<endl;
	int temp_num{},numOnum{}; 
	cin>>numOnum;
	for(int i=0; i!=numOnum; i++){
		cin>>temp_num;
		arr1.insert(temp_num, i);
	}

	arr1.print_arr();
	cout<<endl<<arr1.binSearch(0, arr1.get_size()-1, 40);

}

