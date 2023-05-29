#include<bits/stdc++.h>
using namespace std;

class DiagonalMatrix {
	int *mat;
	int length{};
	public:
	DiagonalMatrix(int n) {
		this->length=n;
		mat=new int[length];
	}
	void setMatrix(int i, int j, int value) {
		if(i==j) mat[i-1]=value;
	}

	int getMatrixValue(int i, int j) {
		if(length<i || length<j) return -1;
		if(i!=j) return 0;
		return mat[i-1];
	}

	void displayMatrix(){
		cout<<"length: "<<length<<endl;
		for(int i=0; i!=length; i++){
			for(int j=0; j!=length; j++) {
				if(i==j) cout<<mat[i]<<"\t ";
				else cout<<0<<"\t ";
			}
			cout<<endl;
		}
	}

	~DiagonalMatrix();
};

DiagonalMatrix::~DiagonalMatrix(){
	delete []mat;
}

int main() {

	DiagonalMatrix m1(5);
	m1.setMatrix(1,1,12);
	m1.setMatrix(2,2,15);
	m1.setMatrix(3,3,96);
	m1.setMatrix(4,4,100);
	m1.setMatrix(5,5,23);

	m1.displayMatrix();


}
