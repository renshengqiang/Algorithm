/*************************************************************************
	> File Name: BSTree.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月04日 星期一 19时13分24秒
 ************************************************************************/

#include "BSTree.h"
#include <iostream>
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
BSTree<KeyType, ValueType>::BSTree()
{
    rootNode = firstNode = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
BSTree<KeyType, ValueType>::~BSTree()
{
	_clear(rootNode);
	rootNode = firstNode = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::_clear(typename BSTree<KeyType, ValueType>::BSTreeNode *root)
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
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::Insert(KeyType key, ValueType value)
{
	return _insert(NULL, &rootNode, key, value);
}
//------------------------------------------------------------------------------------------------------------------------------------------
/*
 * return the parent node of the turely deleted node
 * return NULL means not find the node to find
 */
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::Delete(KeyType key)
{
    typename BSTree<KeyType, ValueType>::BSTreeNode *p = rootNode, *q, *parent;

	while(p && p->key != key){
		if(p->key < key) p = p->rchild;
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
		deletedNodeElement = key;
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
		p->key = q->key;
		deletedNodeElement = q->key;
		delete q;
		return parent;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::Search(KeyType key)
{
	return _search(rootNode, key);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::InOrderTraverse(void)
{
	_inOrderTraverse(rootNode);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::PreOrderTraverse(void)
{
	_preOrderTraverse(rootNode);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::_insert(typename BSTree<KeyType, ValueType>::BSTreeNode *parent, typename BSTree<KeyType, ValueType>::BSTreeNode **root, KeyType key, ValueType value)
{
	if(*root == 0){
        typename BSTree<KeyType, ValueType>::BSTreeNode *pNode = _newNodeImpl();
		pNode->key = key;
        pNode->value = value;
		pNode->parent = parent;
		(*root) = pNode;
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
	}else if(key < (*root)->key) return _insert(*root, &((*root)->lchild),key, value);
	else return _insert(*root, &((*root)->rchild), key, value);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::_search(typename BSTree<KeyType, ValueType>::BSTreeNode *root, KeyType key)
{
	if(root==0) return 0;
	else if(root->key == key) return root;
	else if(key < root->key) return _search(root->lchild, key);
	else return _search(root->rchild, key);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::_inOrderTraverse(typename BSTree<KeyType, ValueType>::BSTreeNode   *root)
{
	if(root == 0) return;
	_inOrderTraverse(root->lchild);
	std::cout << "<" << root->key << " , " << root->value << ">" << std::endl;
	_inOrderTraverse(root->rchild);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
void BSTree<KeyType, ValueType>::_preOrderTraverse(typename BSTree<KeyType, ValueType>::BSTreeNode *root)
{
	if(root == 0) return;
	std::cout << "<" << root->key << " , " << root->value << ">" << std::endl;
	_preOrderTraverse(root->lchild);
	_preOrderTraverse(root->rchild);
}
//------------------------------------------------------------------------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename BSTree<KeyType, ValueType>::BSTreeNode*
BSTree<KeyType, ValueType>::_newNodeImpl(void)
{
    typename BSTree<KeyType, ValueType>::BSTreeNode *pNode = new typename BSTree<KeyType, ValueType>::BSTreeNode();
	pNode->parent = pNode->lchild = pNode->rchild = pNode->pre = pNode->next = NULL;
	return pNode;
}
