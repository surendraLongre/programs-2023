#include<bits/stdc++.h>
using namespace std;

//wring code for ncr that is combination formula's value

int comb(int n, int r){
        if(r==0 || r==n) return 1;
        return comb(n-1,r-1)+comb(n-1,r);
}

int main(){
        cout<<comb(4,2)<<endl;
}
