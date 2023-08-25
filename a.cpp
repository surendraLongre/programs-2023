#include<bits/stdc++.h>
using namespace std;

int power(int m,int n)
{
	if(n==0) return 1;
	return power(m,n-1)*m;
}

int factorial(int num){
	if(num<=1) return 1;
	return factorial(num-1)*num;
}

double tailer(int x, int n){
	
	if(n==0)return 1;
	return tailer(x, n-1)+(double(power(x,n))/factorial(n));
}

double mod_tail(int x,int n){
	double result=1;
	for (n; n!=0; n--){
		result*=(float(x)/n);
		result++;
	}
	return result;
}

double mod_rec_tail(int x,int n){
	static double result=1;
	if(n==0) return result;
	result*=(float(x)/n);
	result++;
	return mod_rec_tail(x,n-1);
}


int main()
{
	cout<<mod_rec_tail(3,10);
}
