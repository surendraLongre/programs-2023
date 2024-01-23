#include<bits/stdc++.h>

int hash_size=10;

int Hash[10]{};

void insert(int);
bool search(int);

int main(){

	insert(10);
	insert(11);
	insert(12);
	insert(13);
	insert(14);
	insert(15);
	insert(16);
	insert(17);
	insert(18);
	insert(19);
//	insert(15);

	std::cout<<"searching"<<std::endl;
	std::cout<<search(20)<<std::endl;

}

void insert(int num){
	int index=num%10;
	int i{};
	while(Hash[index]!=0){
		index+=i;
		index%=hash_size;
		i++;
	}
	Hash[index]=num;
}

bool search(int num){
	int index=num%10;
	int true_index=index;
	int i{};
	while(Hash[index]!=0){
		if(Hash[index]==num)
			return true;
		i++;
		index+=i;
		index%=hash_size;
		if(true_index==index)
			return false;
	}
	return false;
}
