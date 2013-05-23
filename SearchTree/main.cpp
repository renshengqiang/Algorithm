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
	AVLTree<int> itree;

	std::cout << "Insert 0 9 4 6 -4 -2 -1\n";
	itree.Insert(0);
	itree.Insert(9);
	itree.Insert(4);
	itree.Insert(6);
	itree.Insert(-4);
	itree.Insert(-2);
	itree.Insert(-1);
    
    std::cout << "traverse through thread info:\n";
    BSTreeNode<int> *firstNode = itree.GetFirstNode();
    while(firstNode){
        std::cout << firstNode->element << " ";
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
//-----------------------------------------------------------------------------------------
	AVLTree<std::string> strTree;

	std::cout << "Inserted 5 string: rensehngqiang shibojun lijin wangzaibing zhaogang\n";
	strTree.Insert("renshengqiang");
	strTree.Insert("shibojun");
	strTree.Insert("lijin");
	strTree.Insert("wangzaibing");
	strTree.Insert("zhaogang");

	std::cout << "InOrder traverse:\n";
	strTree.InOrderTraverse();
	std::cout << "PreOrder traverse:\n";
	strTree.PreOrderTraverse();

	std::cout << "Look for lijin:\n";
	AVLTreeNode<std::string> *pNode = strTree.Search("lijin");
	if(pNode != 0) std::cout << pNode->element << std::endl;

	std::cout << "Look for huangliangyu\n";
	pNode = strTree.Search("huangliangyu");
	if(pNode != 0) std::cout << pNode->element << std::endl;

	return 0;
}
