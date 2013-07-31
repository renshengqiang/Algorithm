#include "Bitree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <queue>

//Desc: init a bitree from preorder traverse sequence and inorder traverse sequence, a recursive implementation
void _InitTree(Bitree *root, const char *preOrderSequence, int preBegin, int preEnd, 
                const char *inOrderSequence, int inBegin, int inEnd)
{
    //error check
    if(preEnd - preBegin != inEnd - inBegin)
    {
        fprintf(stderr, "Error _InitTree: preOrerSequence's length is not equal to inOrderSequence's length\n");
        *root = NULL;
        return;
    }

    //exit condition
    if(preBegin > preEnd)
    {
        *root = NULL;
        return;
    }

    //normal condition
    *root = (Bitree)malloc(sizeof(BitreeNode));
    (*root)->data = preOrderSequence[preBegin];

    //find the mid pos
    int preLength = -1; //preOrderSequence[preBegin]在中序序列中与中序序列开头的距离
    for(int i= inBegin; i<=inEnd; ++i)
    {
        if(inOrderSequence[i] == preOrderSequence[preBegin])
        {
            preLength = i - inBegin;
            break;
        }
    }
    if(preLength == -1)
    {
        fprintf(stderr, "Error _InitTree: two sequence dismatch\n");
        (*root)->lchild = (*root)->rchild = NULL;
        return;
    }

    _InitTree(&((*root)->lchild), preOrderSequence, preBegin + 1, preBegin + preLength,
                inOrderSequence, inBegin, inBegin + preLength - 1);
    _InitTree(&((*root)->rchild), preOrderSequence, preBegin + preLength + 1, preEnd,
            inOrderSequence, inBegin + preLength + 1, inEnd);
}
//Desc: create a Bitree from preOrderSequence and inOrderSequence
//return the initial tree 
Bitree InitTree(const char *preOrderSequence, const char *inOrderSequence)
{
    if(preOrderSequence == NULL || inOrderSequence == NULL) return NULL;
    
    int preLength = strlen(preOrderSequence);
    int inLength = strlen(inOrderSequence);
    Bitree tree = NULL;

    _InitTree(&tree, preOrderSequence, 0, preLength-1,
                inOrderSequence, 0, inLength-1);
    return tree;
}

void PreOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        printf("%c", tree->data);
        PreOrderTraverseRecursive(tree->lchild);
        PreOrderTraverseRecursive(tree->rchild);
    }
}
void PreOrderTraverseNonRecursive(Bitree tree)
{
    std::stack<BitreeNode*> stack;
    BitreeNode* pNode = tree;

    while(!stack.empty() || pNode!=NULL)
    {
        if(pNode == NULL)
        {
            pNode = stack.top();
            stack.pop();
            pNode = pNode->rchild;
        }
        else
        {
            printf("%c", pNode->data);
            stack.push(pNode);
            pNode = pNode->lchild;
        }
    }
}

void InOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        InOrderTraverseRecursive(tree->lchild);
        printf("%c", tree->data);
        InOrderTraverseRecursive(tree->rchild);
    }
}
void InOrderTraverseNonRecursive(Bitree tree)
{
    std::stack<BitreeNode*> stack;
    BitreeNode* pNode = tree;

    while(!stack.empty() || pNode!=NULL)
    {
        if(pNode == NULL)
        {
            pNode = stack.top();
            stack.pop();
            printf("%c", pNode->data);
            pNode = pNode->rchild;
        }
        else
        {
            stack.push(pNode);
            pNode = pNode->lchild;
        }
    }
}

void BackOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        BackOrderTraverseRecursive(tree->lchild);
        BackOrderTraverseRecursive(tree->rchild);
        printf("%c", tree->data);
    }
}
struct StackItem
{
    BitreeNode *pNode;
    int count;
};
void BackOrderTraverseNonRecursive(Bitree tree)
{
    std::stack<StackItem> stack;
    StackItem item;
    item.pNode = tree;
    item.count = 0;

    while(item.pNode!=NULL || !stack.empty())
    {
        if(item.pNode == NULL)
        {
            item = stack.top();
            stack.pop();
            if(item.count == 2)
            {
                printf("%c", item.pNode->data);
                item.pNode = NULL;
            }
            else
            {
                item.count++;
                stack.push(item);
                item.pNode = item.pNode->rchild;
                item.count = 0;
            }
        }
        else
        {
            item.count++;
            stack.push(item);
            item.pNode = item.pNode->lchild;
            item.count = 0;
        }
    }
}

void LayerOrderTraverse(Bitree tree)
{
    std::queue<BitreeNode*> queue;
    BitreeNode *pNode;
    
    queue.push(tree);
    while(!queue.empty())
    {
        pNode = queue.front();
        queue.pop();
        
        if(pNode)
        {
            printf("%c", pNode->data);
            queue.push(pNode->lchild);
            queue.push(pNode->rchild);
        }
    }
}

int TreeDepth(Bitree tree)
{
    if(tree == NULL)
        return 0;
    int leftDepth  = TreeDepth(tree->lchild);
    int rightDepth = TreeDepth(tree->rchild);

    return leftDepth > rightDepth? leftDepth + 1: rightDepth + 1;
}

int _NearParent(Bitree tree,  char first,  char second, Bitree *result)
{
    if(tree == NULL) return 0;
    if(tree->data == first || tree->data == second) return 1;
    int leftRes = _NearParent(tree->lchild, first, second, result);
    if(leftRes > 1) return leftRes;
    int rightRes = _NearParent(tree->rchild, first, second, result);
    if(rightRes > 1) return rightRes;

    if(leftRes == 1 && rightRes == 1)
    {
        *result = tree;
    }
    return leftRes + rightRes;
}
BitreeNode* NearestParent(Bitree tree, char first, char second)
{
    BitreeNode *res = NULL;
    
    _NearParent(tree, first, second, &res);
    return res;
}
