#include<bits/stdc++.h>
using namespace std;

class LowerTriangularMatrix{
	int *arr;
	int length{};
public:
	LowerTriangularMatrix(int length){
		this->length=length;
		arr=new int[length];
	}

	void setMatrix(int, int, int);
	void getMatrix(int, int);
	int display();

	~LowerTriangularMatrix();
};

void LowerTriangularMatrix::setMatrix(int i, int j, int value){
	i-=1; j-=1;
	if(i>=j){
		arr[i*(i-1)/2+j-1]=value
	}
}

int LowerTriangularMatrix::getMatrix(int i, int j){
	if(i<j) return 0;
	return arr[i*(i-1)/2+j-1];
}

void LowerTriangularMatrix::display(){
	for(int i=0; i!=length; i++){
		for(int j=0; j!=length; j++) {
			cout<<getMatrix(i,j)<<" ";
		}
		cout<<endl;
	}
}

void LowerTriangularMatrix::~LowerTriangularMatrix(){
	delete []arr;
}

int main() {
	LowerTriangularMatrix m1(3);
	m1.setMatrix(1,1,12);
	m1.setMatrix(2,1,15);
	m1.setMatrix(2,2,16);
	m1.setMatrix(3,1,23);
	m1.setMatrix(3,2,25);
	m1.setMatrix(3,3,96);

	m1.display();
}
