#include<bits/stdc++.h>
//using namespace std;

class Matrices
{
	public:
	int matrix[50]{};
	int currentSize{};
	void insert(int);
};


class Diagonal:public Matrices{
public:
	Diagonal();
	void print();
	int getOrder();
	int get(int, int);
};

int Diagonal::getOrder(){
	return currentSize;
}

class LowerTriangular:public Matrices{
	public:
		void print();
		int get(int,int);
		int getOrder();

};

class UpperTriangular:public Matrices{
	public:
		void print();
		int get(int,int);
		int getOrder();

};

int UpperTriangular::getOrder(){
	return (sqrt(1+8*currentSize)-1)/2;
}

int LowerTriangular::getOrder(){
	return (sqrt(1+8*currentSize)-1)/2;
}

int LowerTriangular::get(int i, int j){
	if(j>i) return 0;
	return matrix[((i)*(i+1))/2+j];
}

int UpperTriangular::get(int i, int j){
	if(i>j) return 0;
	return matrix[((j)*(j+1))/2+i];
}

Diagonal::Diagonal(){}

void Matrices::insert(int num){
	if(currentSize!=50){
	matrix[currentSize]=num;
	currentSize++;
	}
	else
		std::cout<<"size exceeded"<<std::endl;
}

void LowerTriangular::print(){
	for(int i=0; i!=getOrder(); i++){
		for(int j=0; j!=getOrder(); j++){
			std::cout<<get(i,j)<<" ";		
		}
		std::cout<<std::endl;
	}
}

void UpperTriangular::print(){
	for(int i=0; i!=getOrder(); i++){
		for(int j=0; j!=getOrder(); j++){
			std::cout<<get(i,j)<<" ";		
		}
		std::cout<<std::endl;
	}
}

void Diagonal::print(){
	for(int i=0; i!=currentSize*currentSize; i++){
		if(i%(currentSize+1)==0) std::cout<<matrix[i/(currentSize+1)]<<" ";
		else std::cout<<0<<" ";
		if((i+1)%currentSize==0) std::cout<<std::endl;
	}
}

int Diagonal::get(int i, int j){
	if(!(i<currentSize && j<currentSize)){
		std::cout<<"index exceeded"<<std::endl;
		return -1;
	}
	if(i!=j) return 0;
	else return matrix[i];
}

int main()
{
	UpperTriangular diag1;
	diag1.insert(10);
	diag1.insert(30);
	diag1.insert(20);
	diag1.insert(50);
	diag1.insert(70);
	diag1.insert(25);

	diag1.print();
}
