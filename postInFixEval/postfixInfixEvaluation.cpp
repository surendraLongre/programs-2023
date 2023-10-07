#include<bits/stdc++.h>
#include "postfix.h"
//not implementing unneccessary checks for example index out of range and so on,
//Symbol 	OutsideStackPre		InsideStackPre
//+,-		1			2
//*,/		3			4
//^		6			5
//(		7			0
//)		0			?
//
//
//use the command:
//g++ a.cpp charStack.cpp postfix.cpp intStack.cpp -o a.out; ./a.out
//to get the result

int main()
{
	char arr[]="3+5+6^2";
	Postfix p1;
	p1.convert(arr);
	p1.print();
	std::cout<<p1.evaluate()<<std::endl;
}
