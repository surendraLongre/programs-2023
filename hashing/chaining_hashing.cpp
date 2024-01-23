#include<bits/stdc++.h>
#include "list.h"

//this is a program for chaining hashing

List *hash[10];

void insert(int);
bool search(int);

int main(){
	//for the chaining hashing
	for(int i=0; i!=10; i++){
		hash[i]=new List;
	}
	insert(100);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(1000);
	insert(32);

	hash[0]->print();
	std::cout<<search(100);
	hash[2]->print();

//for linear probing

}

void insert(int num){
	hash[num%10]->push(num);
}

bool search(int num){
	return hash[num%10]->search(num);
}
