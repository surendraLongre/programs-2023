#include<bits/stdc++.h>
using namespace std;

//here counting starts from 1
int fib_loop(int nth_term){
	int s0=0, t0=0,t1=1;
	for(int i=3; i!=nth_term+1; i++){
		s0=t0+t1;
		t0=t1;
		t1=s0;
	}

	return s0;
}	


//here counting starts from 0
//but this is time consuming because it has order as 2^n

int fib_rec(int nth_term){
	if(nth_term==0)return 0;
	if(nth_term<=2)return 1;
	return fib_rec(nth_term-2)+fib_rec(nth_term-1);
}

//define an array which stores value for fib sequence
int arr[30]{0,1};

int fib_opt_rec(int nth_term){

	if(arr[nth_term-2]==-1) arr[nth_term-2]=fib_opt_rec(nth_term-2);
	if(arr[nth_term-1]==-1) arr[nth_term-1]=fib_opt_rec(nth_term-1);
	return arr[nth_term-2]+arr[nth_term-1];
}

int main()
{
	for(int i=2; i!=30; i++) arr[i]=-1;
	cout<<fib_opt_rec(5)<<endl;
}
