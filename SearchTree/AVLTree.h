/*************************************************************************
	> File Name: AVLTree.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月05日 星期二 15时36分22秒
 ************************************************************************/
#ifndef _AVLTREE_H
#define _AVLTREE_H
#include "BSTree.h"

template <typename ElementType>
class AVLTreeNode : public BSTreeNode<ElementType>{
		public:
				int bf;
};
 
template <typename ElementType>
class AVLTree : public BSTree<ElementType> {
		public:
				AVLTree();
				virtual ~AVLTree();
				virtual AVLTreeNode<ElementType> *Insert(ElementType element);
				virtual AVLTreeNode<ElementType> *Delete(ElementType element);
				virtual AVLTreeNode<ElementType> *Search(ElementType element);
		protected:
				AVLTreeNode<ElementType> *_newNodeImpl(void);
};

#include "AVLTree.cpp"
#endif
