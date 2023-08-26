#include<bits/stdc++.h>
using namespace std;

//wring code for ncr that is combination formula's value

void TOH(int diskr, int A, int B, int C){
        if (diskr>0){
                //transfer the disk to the b box first
                TOH(diskr-1, A,C,B);
                cout<<A<<", "<<C<<endl;

                //now transfer the disks to the c box which is the destination as well
                TOH( diskr-1,B,A,C );
        }
}

int main(){
        TOH(3,1,2,3);
}
