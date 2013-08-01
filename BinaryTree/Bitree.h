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
//按行打印，一层一行
void LayerOrderTraverse2(Bitree tree);
//遍历指定的一行，根是第0行
void TraverseLayer(Bitree tree, int layer);

//calc the height of the tree
int TreeDepth(Bitree tree);

//find the nearest parent of two node
BitreeNode* NearestParent(Bitree tree, char first, char second);
#endif
