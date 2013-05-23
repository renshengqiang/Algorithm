/*************************************************************************
	> File Name: BSTree.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月04日 星期一 18时58分02秒
 ************************************************************************/
#ifndef _BSTREE_H
#define _BSTREE_H
template <typename ElementType>
class BSTreeNode{
		public:
				ElementType element;
				BSTreeNode<ElementType> *parent;
				BSTreeNode<ElementType> *lchild,*rchild;
				BSTreeNode<ElementType> *pre,*next;
};
template <typename ElementType>
class BSTree {
		public:
				BSTree();
				virtual ~BSTree();
                BSTreeNode<ElementType>* GetFirstNode(void){ return firstNode;}
				virtual BSTreeNode<ElementType> *Insert(ElementType element);
				virtual BSTreeNode<ElementType> *Delete(ElementType element);
				virtual BSTreeNode<ElementType> *Search(ElementType element);
				virtual void InOrderTraverse(void);
				virtual void PreOrderTraverse(void);
		protected:
				virtual BSTreeNode<ElementType> *_newNodeImpl(void);
				BSTreeNode<ElementType> *rootNode, *firstNode;
				ElementType deletedNodeElement;
		private:
				void _clear(BSTreeNode<ElementType> *root);
				BSTreeNode<ElementType>* _insert(BSTreeNode<ElementType> *parent, BSTreeNode<ElementType> **root, ElementType element);
				BSTreeNode<ElementType>* _search(BSTreeNode<ElementType> *root, ElementType element);
				void _inOrderTraverse(BSTreeNode<ElementType> *root);
				void _preOrderTraverse(BSTreeNode<ElementType> *root);
};
#include "BSTree.cpp"
#endif
