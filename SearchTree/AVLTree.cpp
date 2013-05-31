/*************************************************************************
	> File Name: AVLTree.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月05日 星期二 15时53分04秒
 ************************************************************************/
#include "AVLTree.h"

//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void _leftRotate(typename AVLTree<KeyType, ValueType>::AVLTreeNode* &p)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *t = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)p->rchild;
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
template <typename KeyType, typename ValueType>
void _rightRotate(typename AVLTree<KeyType, ValueType>::AVLTreeNode* &p)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *t = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)p->lchild;
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
template <typename KeyType, typename ValueType>
void _leftBalance(typename AVLTree<KeyType, ValueType>::AVLTreeNode* &p)
{
    typename AVLTree<KeyType, ValueType>::AVLTreeNode *pRightChild = (typename AVLTree<KeyType, ValueType>::AVLTreeNode *)p->rchild;
	if(pRightChild->bf == 1){
		_rightRotate<KeyType, ValueType>(pRightChild);
		p->rchild = (typename AVLTree<KeyType, ValueType>::AVLTreeNode *)pRightChild;
	}
	_leftRotate<KeyType, ValueType>(p);
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void _rightBalance(typename AVLTree<KeyType, ValueType>::AVLTreeNode* &p)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *pLeftChild = (typename AVLTree<KeyType, ValueType>::AVLTreeNode *)p->lchild;
	if(pLeftChild->bf == -1){
		_leftRotate<KeyType, ValueType>(pLeftChild);
		p->lchild = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)pLeftChild;
	}
	_rightRotate<KeyType, ValueType>(p);
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
AVLTree<KeyType, ValueType>::AVLTree():
	BSTree<KeyType, ValueType>()
{
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
AVLTree<KeyType, ValueType>::~AVLTree()
{
}
//---------------------------------------------------------------------------------
#define  c_p pParentNode->parent 
#define  c_root (c_p?((c_p->lchild == pParentNode)?c_p->lchild:c_p->rchild):this->rootNode)
template <typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::AVLTreeNode* 
AVLTree<KeyType, ValueType>::Insert(KeyType key, ValueType value)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *pParentNode = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)BSTree<KeyType, ValueType>::Insert(key, value);
	const KeyType *pkey = &key;

	if(pParentNode == NULL) return NULL;
	while(pParentNode){
		pParentNode->bf += (pParentNode->key > *pkey) ? 1:-1;
		if(pParentNode->bf == -2) _leftBalance<KeyType, ValueType>((typename AVLTree<KeyType, ValueType>::AVLTreeNode* &)c_root);
		else if(pParentNode->bf == 2) _rightBalance<KeyType, ValueType>((typename AVLTree<KeyType, ValueType>::AVLTreeNode* &)c_root);
		if(pParentNode->bf == 0) break;/*insert and rotate end*/
		pkey = &(pParentNode->key);
		pParentNode = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)pParentNode->parent;
	}
	return pParentNode;
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::AVLTreeNode* 
AVLTree<KeyType, ValueType>::Delete(KeyType key)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *pParentNode = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)BSTree<KeyType, ValueType>::Delete(key);
	const KeyType *pkey = &(this->deletedNodeElement);

	while(pParentNode){
		pParentNode->bf += (pParentNode->key < *pkey) ? 1 : -1;
		if(pParentNode->bf == -2) _leftBalance<KeyType, ValueType>((typename AVLTree<KeyType, ValueType>::AVLTreeNode* &)c_root);
		else if(pParentNode->bf == 2) _rightBalance<KeyType, ValueType>((typename AVLTree<KeyType, ValueType>::AVLTreeNode* &)c_root);
		if(pParentNode->bf) break;
		pkey = &(pParentNode->key);
		pParentNode = (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)pParentNode->parent;
	}
	return pParentNode;
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::AVLTreeNode*
AVLTree<KeyType, ValueType>::Search(KeyType key)
{
	return (typename AVLTree<KeyType, ValueType>::AVLTreeNode*)BSTree<KeyType, ValueType>::Search(key);
}
//---------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::AVLTreeNode*
AVLTree<KeyType, ValueType>::_newNodeImpl(void)
{
	typename AVLTree<KeyType, ValueType>::AVLTreeNode *pNode = new typename AVLTree<KeyType, ValueType>::AVLTreeNode();
	pNode->bf = 0;
	pNode->parent = pNode->lchild = pNode->rchild = pNode->pre = pNode->next = NULL;
	return pNode;
}
