#include<bits/stdc++.h>

class Stack{
	int *arr;
	int size{};
	int top=-1;
public:
	Stack(int);
	void push(int);
	int pop();
	void print();
	int peek(int); //element where the top points has got the index as 1 in our case.
	int stackTop();
	int isEmpty();
	int isFull();
};

Stack::Stack(int size){
	this->size=size;
	arr=new int[size];
}

void Stack::push(int num){
	if(top==size-1){
		std::cout<<"Stack is full"<<std::endl;
		return;
	}
	top++;
	arr[top]=num;
}

int Stack::pop(){
	if(top==-1){
		std::cout<<"Stack is empty"<<std::endl;
		return -1;
	} 

	int to_return=arr[top];
	top--;
	return to_return;
}

void Stack::print(){
	for(int i=0; i<=top; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

int Stack::peek(int index){
	if(index<1 || index>top+1){
		std::cout<<"invalid index"<<std::endl;
		return -1;
	}
	return arr[top+1-index];
}

int Stack::stackTop(){
	if(top!=-1)
		return arr[top];
	std::cout<<"stack is empty";
	return -1;
}

int Stack::isEmpty(){
	return (top==-1?1:0);
}

int Stack::isFull(){
	return (top==size-1?1:0);
}

int main()
{
	Stack st1(5);
	st1.push(3);
	st1.push(4);
	st1.push(9);
	st1.push(7);
	st1.push(7);
	st1.push(7);
	st1.print();

	st1.pop();
	st1.pop();
	st1.pop();
	st1.pop();
	st1.pop();
	st1.pop();

	st1.push(23);
	st1.push(99);
	st1.print();
	std::cout<<st1.isFull();
}
