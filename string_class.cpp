#include<bits/stdc++.h>
using namespace std;

class String {
	char *ch;
public:
	String(char *str) {
		ch=str;
	}

	int str_length(){
		int to_return{};
		for(int i=0; ch[i]!='\0'; i++) {
			to_return++;
		}
		return to_return;
	}

	void display(){
		for(int i=0; ch[i]!='\0'; i++) cout<<ch[i]; cout<<endl;
	}

	void reverse() {
		int length=str_length();
		for(int i=0; i!=floor(int(length/2)); i++) {
			char temp=ch[i];
			ch[i]=ch[length-i-1];
			ch[length-i-1]=temp;
		}
	}

	//duplicates using hash table
	void duplicates() {
		int arr[26]{};
		for(int i=0; ch[i]!='\0'; i++) {
			arr[int(ch[i])-97]+=1;
		}
		for(int i=0; i!=26; i++) {
			if(arr[i]>1) cout<<char(97+i)<<endl;
		}
	}

	//duplicates using bitwise operators
	void duplicates_bit(){
		int hash=0;
		for(int i=0; ch[i]!='\0'; i++) {
			int check=1;
			check=(check<<(int(ch[i])-97));
			if((hash&check)) cout<<ch[i]<<endl;
			else hash=(hash|check);
		}
	}

};

int main() {
	char ch[]={97, 97, 98, 100, 101, 102, 102};
	String str1(ch);
	cout<<str1.str_length();
	cout<<endl;
	str1.display();
	str1.duplicates_bit();

}
