#include<bits/stdc++.h>
#include "queue.h"

int main(){
	int vertices{};//, edges{};
	std::cout<<"Enter the no. of vertices: "; std::cin>>vertices; vertices++;
//	std::cout<<"Enter the no. of edges: "; std::cin>>edges;

	int arr[vertices][vertices]{};
	int visited[vertices]{};
	char user_input{};
	Queue test;

	for(int i=1; i!=vertices; i++){
		for(int j=1; j!=vertices; j++){
			std::cout<<i<<" is connected to "<<j<<"? "; std::cin>>user_input;
			if(user_input=='y' || user_input=='Y')
				arr[i][j]=1;
		}
	}

	//write to visit the nodes
//	for(int i=1; i!=vertices; i++){
//		for(int j=0; j!=vertices; j++){
//			if(arr[i][j]==1){
//				if(!visited[j]){
//					test.push(j);
//					visited[j]=1;
//				}
//			}
//		}
//	}

	int i=1;
	visited[i]=1;
	test.push(i);

	while(!test.isEmpty()){
		i=test.pop();
		std::cout<<i<<" ";
		for(int j=1; j!=vertices; j++){
			if(arr[i][j]==1){
//				std::cout<<i<<" is connected to "<<j<<std::endl;
				if(!visited[j]){
					test.push(j);
					visited[j]=1;
				}
			}
		}
	}
}
