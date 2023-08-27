#include<bits/stdc++.h>
using namespace std;

int main()
{
        //creating 2D arrays
        //in this case the array pointers are in stack however, the arrays are in heap
        int *A[3];
        A[0]=new int[4];
        A[1]=new int[4];
        A[2]=new int[4];

        //creating almost every part of array in heap using double pointers
        int **B;
        B=new int*[3];
        B[0]=new int[4];
        B[1]=new int[4];
        B[1]=new int[4];
}
