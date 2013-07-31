#ifndef _BITREE_H
#define _BITREE_H

//data structure
typedef struct BitreeNode{
    char data;
    struct BitreeNode *lchild, *rchild;
}BitreeNode, *Bitree;

//algorithm

//init the binary three
Bitree InitTree(const char *preOrderSequence, const char *inOrderSequence);

//traverse
void PreOrderTraverseRecursive(Bitree tree);
void PreOrderTraverseNonRecursive(Bitree tree);

void InOrderTraverseRecursive(Bitree tree);
void InOrderTraverseNonRecursive(Bitree tree);

void BackOrderTraverseRecursive(Bitree tree);
void BackOrderTraverseNonRecursive(Bitree tree);

void LayerOrderTraverse(Bitree tree);

//calc the height of the tree
int TreeDepth(Bitree tree);

//find the nearest parent of two node
BitreeNode* NearestParent(Bitree tree, char first, char second);
#endif
