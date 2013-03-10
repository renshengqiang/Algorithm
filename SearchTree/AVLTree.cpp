/*************************************************************************
	> File Name: AVLTree.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月05日 星期二 15时53分04秒
 ************************************************************************/
#include "AVLTree.h"
//---------------------------------------------------------------------------------
template <typename ElementType>
void _leftBalance(AVLTreeNode<ElementType>* &p)
{
	AVLTreeNode<ElementType> *pRightChild = (AVLTreeNode<ElementType> *)p->rchild;
	if(pRightChild->bf == 1){
		_rightRotate(pRightChild);
		p->rchild = (BSTreeNode<ElementType> *)pRightChild;
	}
	_leftRotate(p);
}
//---------------------------------------------------------------------------------
template <typename ElementType>
void _rightBalance(AVLTreeNode<ElementType>* &p)
{
	AVLTreeNode<ElementType> *pLeftChild = (AVLTreeNode<ElementType> *)p->lchild;
	if(pLeftChild->bf == -1){
		_leftRotate(pLeftChild);
		p->lchild = (BSTreeNode<ElementType> *)pLeftChild;
	}
	_rightRotate(p);
}
//---------------------------------------------------------------------------------
template <typename ElementType>
void _leftRotate(AVLTreeNode<ElementType>* &p)
{
	AVLTreeNode<ElementType> *t = (AVLTreeNode<ElementType>*)p->rchild;
	t->parent = p->parent;
	p->parent = t;
	p->rchild = t->lchild;
	if(t->lchild) t->lchild->parent = p;
	t->lchild = p;
	++(p->bf) -= t->bf < 0 ? t->bf : 0;
	++(t->bf) += p->bf > 0 ? p->bf : 0;
	p = t;
}
//---------------------------------------------------------------------------------
template <typename ElementType>
void _rightRotate(AVLTreeNode<ElementType>* &p)
{
	AVLTreeNode<ElementType> *t = (AVLTreeNode<ElementType>*)p->lchild;
	t->parent = p->parent;
	p->parent = t;
	p->lchild = t->rchild;
	if(t->rchild) t->rchild->parent = p;
	t->rchild = p;
	--(p->bf) -= t->bf > 0 ? t->bf : 0;
	--(t->bf) += p->bf < 0 ? p->bf : 0;
	p = t;
}
//---------------------------------------------------------------------------------
template <typename ElementType>
AVLTree<ElementType>::AVLTree():
	BSTree<ElementType>()
{
}
//---------------------------------------------------------------------------------
template <typename ElementType>
AVLTree<ElementType>::~AVLTree()
{
}
//---------------------------------------------------------------------------------
#define  c_p pParentNode->parent 
#define  c_root (c_p?((c_p->lchild == pParentNode)?c_p->lchild:c_p->rchild):this->rootNode)
template <typename ElementType>
AVLTreeNode<ElementType> *AVLTree<ElementType>::Insert(ElementType element)
{
	AVLTreeNode<ElementType> *pParentNode = (AVLTreeNode<ElementType>*)BSTree<ElementType>::Insert(element);
	const ElementType *pElement = &element;

	if(pParentNode == NULL) return NULL;
	while(pParentNode){
		pParentNode->bf += (pParentNode->element > *pElement) ? 1:-1;
		if(pParentNode->bf == -2) _leftBalance((AVLTreeNode<ElementType> *&)c_root);
		else if(pParentNode->bf == 2) _rightBalance((AVLTreeNode<ElementType> *&)c_root);
		if(pParentNode->bf == 0) break;/*insert and rotate end*/
		pElement = &(pParentNode->element);
		pParentNode = (AVLTreeNode<ElementType>*)pParentNode->parent;
	}
	return pParentNode;
}
//---------------------------------------------------------------------------------
template <typename ElementType>
AVLTreeNode<ElementType> *AVLTree<ElementType>::Delete(ElementType element)
{
	AVLTreeNode<ElementType> *pParentNode = (AVLTreeNode<ElementType>*)BSTree<ElementType>::Delete(element);
	const ElementType *pElement = &this->deletedNodeElement;

	while(pParentNode){
		pParentNode->bf += (pParentNode->element < *pElement) ? 1 : -1;
		if(pParentNode->bf == -2) _leftBalance((AVLTreeNode<ElementType> *&)c_root);
		else if(pParentNode->bf == 2) _rightBalance((AVLTreeNode<ElementType> *&)c_root);
		if(pParentNode->bf) break;
		pElement = &(pParentNode->element);
		pParentNode = (AVLTreeNode<ElementType>*)pParentNode->parent;
	}
	return pParentNode;
}
//---------------------------------------------------------------------------------
template <typename ElementType>
AVLTreeNode<ElementType> *AVLTree<ElementType>::Search(ElementType element)
{
	return (AVLTreeNode<ElementType>*)BSTree<ElementType>::Search(element);
}
//---------------------------------------------------------------------------------
template <typename ElementType>
AVLTreeNode<ElementType> *AVLTree<ElementType>::_newNodeImpl(void)
{
	AVLTreeNode<ElementType> *pNode = new AVLTreeNode<ElementType>();
	pNode->bf = 0;
	pNode->parent = pNode->lchild = pNode->rchild = NULL;
	return pNode;
}
