//postfix.h
#ifndef POSTFIX_H
#define POSTFIX_H
#include "charStack.h"
#include "intStack.h"

class Postfix{
	Stack postfixed;
	Stack opt;

public:
	void convert(char *);
	void print();
	bool isOperand(char);
	int inStackPre(char);
	int outStackPre(char);
	int evaluate();
};

#endif
