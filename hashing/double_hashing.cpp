#include<bits/stdc++.h>

int hash_size=10;

int Hash[10]{};

//write functions to enter the values
void insert(int);
bool search(int);

void print();

int main()
{
	insert(5);
	insert(25);
	insert(35);
	insert(45);
	insert(55);
	insert(65);
	insert(75);
	insert(85);
	insert(95);
	insert(23);
	std::cout<<search(25)<<std::endl;
	std::cout<<std::endl;
	print();
}

void insert(int num){
	int h1=num%hash_size;
	if(!Hash[h1]){
		Hash[h1]=num;
		return;
	}

	int R=7; // R is the prime number closest to the array_size;
	int h2=R-(num%R);

	//bug: the program do not check if there is no space emtpy in the array
	//this bug has been fixed;

	int condition_to_in=(h1+h2)%hash_size;
	int i=1;

	while(Hash[condition_to_in]!=0 && condition_to_in!=h1){
		i++;
		condition_to_in=(h1+h2*i)%10;
	}

	if(condition_to_in!=h1)
		Hash[condition_to_in]=num;
	else
		std::cout<<"no extra size"<<std::endl;
}

bool search(int num){
	int h1=num%hash_size;
	if(Hash[h1]==num)
		return true;
	int R=7; // R is the prime number closest to the array_size;
	int h2=R-(num%R);

	int condition_to_in=(h1+h2)%hash_size;
	int i=1;

	while(condition_to_in!=h1){
		if(Hash[condition_to_in]==num)
			return true;
		i++;
		condition_to_in=(h1+h2*i)%10;
	}
	return false;

}

void print(){
	for(int i=0; i!=hash_size; i++){
		std::cout<<Hash[i]<<" ";
	}
}
