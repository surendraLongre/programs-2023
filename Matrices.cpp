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

class Symmetric:public Matrices{
	public:
		void print();
		int get(int,int);
		int getOrder();
};

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

class Toeplitz:public Matrices{
// the numbers are stored in a row is to column fashion that is considering i=0, then i!=0;
	public:
		void print();
		int get(int,int);
		int getOrder();

};

class Element{
	public:
	int row{}, col{}, val{};
};

class Sparse:public Matrices, Element{
	int m{}, n{}, num{};
	Element *e;

	public:
	Sparse();
	Sparse(int, int, int);
	void print();
	friend Sparse add(Sparse &s1, Sparse &s2);

};

Sparse::Sparse(){
	std::cout<<"Entering sparse constructor"<<std::endl;
	std::cout<<"m: "; std::cin>>m;
	std::cout<<"n: "; std::cin>>n;
	std::cout<<"num: ";std::cin>>num;
	e=new Element[num];

	for(int x=0; x!=num; x++){
		std::cout<<"for "<<x+1<<"th element, row: "; std::cin>>e[x].row;
		std::cout<<"for "<<x+1<<"th element, col: "; std::cin>>e[x].col;
		std::cout<<"for "<<x+1<<"th element, val: "; std::cin>>e[x].val;
		std::cout<<std::endl;
	}
	std::cout<<"created"<<std::endl;
}

Sparse::Sparse(int m, int n, int num){
	this->m=m;
	this->n=n;
	this->num=num;
	e=new Element[num];
}

void Sparse::print(){
	std::cout<<"row\tcol\tval"<<std::endl;
	for(int x=0; x!=num; x++){
		std::cout<<e[x].row<<"\t";
		std::cout<<e[x].col<<"\t";
		std::cout<<e[x].val;
		std::cout<<std::endl;
	}
}

int Toeplitz::get(int i, int j){
	if(i==1){
		return matrix[j-1];
	}
	else if(j==1){
		return matrix[getOrder()+i-2];
	}
	return get(i-1, j-1);
}

void Toeplitz::print(){
	for(int i=0; i!=getOrder(); i++){
		for(int j=0; j!=getOrder(); j++){
			std::cout<<get(i+1,j+1)<<" ";
		} std::cout<<std::endl;
	}  
}

int Toeplitz::getOrder(){
	return sqrt(currentSize);
}

int Diagonal::getOrder(){
	return currentSize;
}

int UpperTriangular::getOrder(){
	return (sqrt(1+8*currentSize)-1)/2;
}

int Symmetric::getOrder(){
	return (sqrt(1+8*currentSize)-1)/2;
}


int LowerTriangular::getOrder(){
	return (sqrt(1+8*currentSize)-1)/2;
}

int LowerTriangular::get(int i, int j){
	if(j>i) return 0;
	return matrix[((i)*(i+1))/2+j];
}

int Symmetric::get(int i, int j){
	if(j>i){
		i+=j;
		j=i-j;
		i-=j;
	}
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

void Symmetric::print(){
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

Sparse add(Sparse &s1, Sparse &s2){
	std::cout<<"adding"<<std::endl;
	Sparse to_return(s1.m, s1.n, s1.num+s2.num);
	std::cout<<"created to_return"<<std::endl;
	int counter{}, j{};
	for(int i=0; i!=s1.num; i++){
		if(s1.e[i].row==s2.e[i].row && s1.e[i].col==s2.e[i].col){
			to_return.e[j].row=s1.e[i].row;
			to_return.e[j].col=s1.e[i].col;
			to_return.e[j].val=s1.e[i].val+s2.e[i].val;
			j++;
		}
		else{
			to_return.e[j].row=s1.e[i].row;
			to_return.e[j].col=s1.e[i].col;
			to_return.e[j].val=s1.e[i].val;
			j++;
			to_return.e[j].row=s2.e[i].row;
			to_return.e[j].col=s2.e[i].col;
			to_return.e[j].val=s2.e[i].val;
			j++;
		}
	}

	to_return.num=j;

	return to_return;
}

int main()
{
	Sparse s1,s2;
	Sparse s3=add(s1,s2);
	s3.print();
}
