/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月04日 星期一 19时49分53秒
 ************************************************************************/
#include "AVLTree.h"
#include <string>
#include <iostream>

int main()
{
	AVLTree<int, std::string> itree;

	std::cout << "Insert 0 9 4 6 -4 -2 -1\n";
	itree.Insert(0, "zero");
	itree.Insert(9, "nine");
	itree.Insert(4, "four");
	itree.Insert(6, "six");
	itree.Insert(-4, "negtive 4");
	itree.Insert(-2, "negtive -2");
	itree.Insert(-1, "negtive -1");
    
    std::cout << "traverse through thread info:\n";
    typename BSTree<int, std::string>::BSTreeNode *firstNode = itree.GetFirstNode();
    while(firstNode){
        std::cout << "<" << firstNode->key << ", " << firstNode->value << "> ";
        firstNode = firstNode->next;
    }
    std::cout << "\n-----------------------------\n";

	std::cout << "InOrder traverse:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder traverse:\n";
	itree.PreOrderTraverse();

	std::cout << "Deleted 9:\n";
	itree.Delete(9);
	std::cout << "InOrder:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder:\n";
	itree.PreOrderTraverse();

	std::cout << "Deleted 4:\n";
	itree.Delete(4);
	std::cout << "InOrder:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder:\n";
	itree.PreOrderTraverse();

	std::cout << "Deleted 0:\n";
	itree.Delete(0);
	std::cout << "InOrder:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder:\n";
	itree.PreOrderTraverse();

	std::cout << "Deleted -2:\n";
	itree.Delete(-2);
	std::cout << "InOrder:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder:\n";
	itree.PreOrderTraverse();

	std::cout << "Deleted 6:\n";
	itree.Delete(6);
	std::cout << "InOrder:\n";
	itree.InOrderTraverse();
	std::cout << "PreOrder:\n";
	itree.PreOrderTraverse();

	return 0;
}
