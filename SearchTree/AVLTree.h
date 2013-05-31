/*************************************************************************
	> File Name: AVLTree.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月05日 星期二 15时36分22秒
 ************************************************************************/
#ifndef _AVLTREE_H
#define _AVLTREE_H
#include "BSTree.h"

template <typename KeyType, typename ValueType>
class AVLTree : public BSTree<KeyType, ValueType> {
public:
    class AVLTreeNode: public BSTree<KeyType, ValueType>::BSTreeNode{
        public:
            int bf;
    };
    AVLTree();
    virtual ~AVLTree();
    virtual AVLTreeNode *Insert(KeyType key, ValueType value);
    virtual AVLTreeNode *Delete(KeyType key);
    virtual AVLTreeNode *Search(KeyType key);
protected:
    AVLTreeNode *_newNodeImpl(void);
};

#include "AVLTree.cpp"
#endif
