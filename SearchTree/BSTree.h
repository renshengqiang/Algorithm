/*************************************************************************
	> File Name: BSTree.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年03月04日 星期一 18时58分02秒
 ************************************************************************/
#ifndef _BSTREE_H
#define _BSTREE_H
template <typename KeyType, typename ValueType>
class BSTree {
		public:
                class BSTreeNode{
                public:
                    KeyType key;
                    ValueType value;
                    BSTreeNode  *parent;
                    BSTreeNode  *lchild,*rchild;
                    BSTreeNode  *pre,*next;
                };

				BSTree();
				virtual ~BSTree();
                BSTreeNode* GetFirstNode(void){ return firstNode;}
				virtual BSTreeNode* Insert(KeyType key, ValueType value);
				virtual BSTreeNode* Delete(KeyType key);
				virtual BSTreeNode* Search(KeyType key);
				virtual void InOrderTraverse(void);
				virtual void PreOrderTraverse(void);
		protected:
				virtual BSTreeNode* _newNodeImpl(void);
				BSTreeNode *rootNode, *firstNode;
				KeyType deletedNodeElement;
		private:
				void _clear(BSTreeNode *root);
				BSTreeNode* _insert(BSTreeNode *parent, BSTreeNode **root, KeyType key, ValueType value);
				BSTreeNode* _search(BSTreeNode  *root, KeyType key);
				void _inOrderTraverse(BSTreeNode    *root);
				void _preOrderTraverse(BSTreeNode   *root);
};
#include "BSTree.cpp"
#endif
