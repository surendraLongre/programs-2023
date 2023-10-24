#include<bits/stdc++.h>
#include "tree.h"

int main()
{
	Tree t1;
	t1.preOrder(t1.getRoot());
	std::cout<<std::endl<<t1.nodeCount(t1.getRoot());
	std::cout<<std::endl<<t1.height(t1.getRoot());
	std::cout<<std::endl<<"search result: "<<t1.isPresent(39);
	t1.insert(41);
	t1.preOrder(t1.getRoot());
}
