//postfix.cpp
#include "postfix.h"
#include "charStack.h"
#include "intStack.h"
#include<bits/stdc++.h>

void Postfix::convert(char *arr){
	int i=0;
	while(arr[i]!='\0'){
		if(isOperand(arr[i])){
			postfixed.push(arr[i]);
		} else{
			if(opt.isEmpty() || outStackPre(arr[i])>inStackPre(opt.stackTop())){
				opt.push(arr[i]);
			}else if(outStackPre(arr[i])==inStackPre(opt.stackTop())){
				opt.pop();
				i++; continue;
			}
				       	else{
				postfixed.push(opt.pop());
				i--;
			}
		}
		i++;
	}
	while(!opt.isEmpty()){
		postfixed.push(opt.pop());
	}
}

bool Postfix::isOperand(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')')
		return false;
	return true;
}

void Postfix::print(){
	postfixed.print();
}

int Postfix::outStackPre(char ch){
	if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/') 
		return 3;
	else if(ch=='^')
		return 6;
	else if(ch=='(')
		return 7;
	else if(ch==')')
		return 0;
	return 0;
}

int Postfix::inStackPre(char ch){
	if(ch=='+' || ch=='-')
		return 2;
	else if(ch=='*' || ch=='/') 
		return 4;
	else if(ch=='^')
		return 5;
	else if(ch=='(')
		return 0;
	return 0;
}

int Postfix::evaluate(){
	IntStack result;
	Node *to_loop=postfixed.getFirst();

	while(to_loop!=NULL){
		if(isOperand(to_loop->data)){
			result.push(int(to_loop->data)-int('0'));
		} else {
			int num1=result.pop();
			int num2=result.pop();

			switch(to_loop->data){
				case '+':
					result.push(num1+num2);
					break;
				case '-':
					result.push(num2-num1);
					break;
				case '*':
					result.push(num1*num2);
					break;
				case '/':
					result.push(num2/num1);
					break;
				case '^':
					result.push(pow(num2, num1));
					break;
			}
		}
		to_loop=to_loop->next;
	}
	std::cout<<std::endl;
	to_loop=NULL;
	delete to_loop;
//	result.print();
	return result.evaluated();
}
