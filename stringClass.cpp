#include<bits/stdc++.h>
using namespace std;

class String
{
	char *ch;
	int size{};
public:
	String();
	String(const char arr[]);

	void lowerToUpper();
	void upperToLower();
	char get(int);

	void print();

	void duplicates();
	void duplicates_using_bits();

	bool anagram(String angm);

	void perm(int);

};

String::String(){};

String::String(const char arr[]){
	size=strlen(arr);
	ch=new char[size+1];
	strcpy(ch,arr);
}

char String::get(int index){
	return ch[index];
}

void String::print(){
	cout<<ch<<endl;
}

void String::lowerToUpper(){
	for(int i=0; ch[i]!='\0'; i++){
		if(ch[i]>='a' && ch[i]<='z') ch[i]-=32;
	}
}

void String::upperToLower(){
	for(int i=0; ch[i]!='\0'; i++){
		if(ch[i]>='A' && ch[i]<='Z') ch[i]+=32;
	}
}

void String::duplicates(){
	int arr[26]{};
	for(int i=0; ch[i]!='\0'; i++){
		arr[int(ch[i])-97]++;
	}

	for(int i=0; i!=26; i++){
		if(arr[i]>1) cout<<char(i+97)<<endl;
	}
}

void String::duplicates_using_bits(){

	int H=0;

	for(int i=0; ch[i]!='\0'; i++){
		int shift=1;
		shift=shift<<(ch[i]-97);

		if(H&shift)cout<<ch[i]<<" ";
		else{
			H=(H|shift);
		}
	}
}

bool String::anagram(String angm){
	int H[26]{};

	for(int i=0; ch[i]!='\0'; i++){
		H[ch[i]-97]++;
	}

	for(int i=0; angm.get(i)!='\0'; i++){
		H[angm.get(i)-97]--;
		if(H[angm.get(i)-97]<0) return false;
	}

	for(int i=0; i!=26; i++)
		if(H[i]!=0) return false;
	return true;



}

void String::perm(int k){
	static int A[10]{};
	static char res[10]{};
	int i;
	if(ch[k]=='\0'){
		res[k]='\0';
		cout<<res<<endl;
	}
	for(i=0; ch[i]!='\0'; i++){
		if(A[i]==0){
			res[k]=ch[i];
			A[i]=1;
			perm(k+1);
			A[i]=0;
		}
	}

}

int main()
{
	String str1("ABC");
	str1.perm(0);

}
