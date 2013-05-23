/*************************************************************************
	> File Name: BSTree.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月04日 星期一 19时13分24秒
 ************************************************************************/

#include "BSTree.h"
#include <iostream>
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTree<ElementType>::BSTree()
{
    rootNode = firstNode = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTree<ElementType>::~BSTree()
{
	_clear(rootNode);
	rootNode = firstNode = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
void BSTree<ElementType>::_clear(BSTreeNode<ElementType> *root)
{
	if(root == NULL) return;
	_clear(root->lchild);
	_clear(root->rchild);
	delete root;
}
//------------------------------------------------------------------------------------------------------------------------------------------
/*
 * return parent node of the inserted item
 */
template <typename ElementType>
BSTreeNode<ElementType> *BSTree<ElementType>::Insert(ElementType element)
{
	return _insert(NULL, &rootNode, element);
}
//------------------------------------------------------------------------------------------------------------------------------------------
/*
 * return the parent node of the turely deleted node
 * return NULL means not find the node to find
 */
template <typename ElementType>
BSTreeNode<ElementType> *BSTree<ElementType>::Delete(ElementType element)
{
	BSTreeNode<ElementType> *p = rootNode, *q, *parent;

	while(p && p->element != element){
		if(p->element < element) p = p->rchild;
		else p = p->lchild;
	}
	if(p == NULL) return NULL;/*can not find*/
	if(p->lchild == NULL){
		if(p->parent == NULL){/*p is the root node*/
			rootNode = p->rchild;
			rootNode->parent = NULL;
		}
		else if(p->parent->lchild == p){
			p->parent->lchild = p->rchild;
			if(p->rchild){
                p->rchild->parent = p->parent;
            }
		}else{
			p->parent->rchild = p->rchild;
			if(p->rchild) p->rchild->parent = p->parent;
		}
        if(p->pre){
            p->pre->next = p->next;
        }
        if(p->next){
            p->next->pre = p->pre;
        }
		deletedNodeElement = element;
		parent =  p->parent;
		delete p;
		return parent;
	}else{
		q = p->lchild;
		while(q->rchild) q = q->rchild;

		if(q == p->lchild){
			p->lchild = p->lchild->lchild;
			if(p->lchild) p->lchild->parent = p;
			parent = p;
		}else{
			q->parent->rchild = q->lchild;
			if(q->lchild) q->lchild->parent = q->parent;
			parent = q->parent;
		}
        if(q->pre){
            q->pre->next = q->next;
        }
        if(q->next){
            q->next->pre = q->pre;
        }
		p->element = q->element;
		deletedNodeElement = q->element;
		delete q;
		return parent;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTreeNode<ElementType> *BSTree<ElementType>::Search(ElementType element)
{
	return _search(rootNode, element);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
void BSTree<ElementType>::InOrderTraverse(void)
{
	_inOrderTraverse(rootNode);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
void BSTree<ElementType>::PreOrderTraverse(void)
{
	_preOrderTraverse(rootNode);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTreeNode<ElementType>* BSTree<ElementType>::_insert(BSTreeNode<ElementType> *parent,BSTreeNode<ElementType> **root, ElementType element)
{
	if(*root == 0){
		BSTreeNode<ElementType> *pElement = _newNodeImpl();
		pElement->element = element;
		pElement->parent = parent;
		(*root) = pElement;
        if(parent == NULL){
            (*root)->pre = (*root)->next = NULL;
            firstNode = *root;
        }else{
            if(&(parent->lchild) == root){
                (*root)->pre = parent->pre;
                (*root)->next = parent;
                if(parent->pre) parent->pre->next = *root;
                else firstNode = *root;
                parent->pre = *root;
            }else{
                (*root)->pre = parent;
                (*root)->next = parent->next;
                if(parent->next) parent->next->pre = *root;
                parent->next = *root;
            }
        }
		return parent;
	}else if(element < (*root)->element) return _insert(*root, &((*root)->lchild),element);
	else return _insert(*root, &((*root)->rchild),element);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTreeNode<ElementType>* BSTree<ElementType>::_search(BSTreeNode<ElementType> *root, ElementType element)
{
	if(root==0) return 0;
	else if(root->element == element) return root;
	else if(element < root->element) return _search(root->lchild, element);
	else return _search(root->rchild, element);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
void BSTree<ElementType>::_inOrderTraverse(BSTreeNode<ElementType> *root)
{
	if(root == 0) return;
	_inOrderTraverse(root->lchild);
	std::cout << root->element << std::endl;
	_inOrderTraverse(root->rchild);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
void BSTree<ElementType>::_preOrderTraverse(BSTreeNode<ElementType> *root)
{
	if(root == 0) return;
	std::cout << root->element << std::endl;
	_preOrderTraverse(root->lchild);
	_preOrderTraverse(root->rchild);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename ElementType>
BSTreeNode<ElementType> *BSTree<ElementType>::_newNodeImpl(void)
{
	BSTreeNode<ElementType> *pNode = new  BSTreeNode<ElementType>();
	pNode->parent = pNode->lchild = pNode->rchild = NULL;
	return pNode;
}
