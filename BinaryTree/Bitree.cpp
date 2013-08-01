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

////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////
//
//根据先序遍历序列和中序遍历序列来求解后序遍历序列
//和重建二叉树的想法相同，参数略有变化
//_CalcBackOrderSequence是功能函数，CalcBackSequence是接口函数
bool _CalcBackOrderSequence(const char *pPre, int preBegin, int preEnd,
                            const char *pMid, int midBegin, int midEnd,
                            char      *pBack, int backBegin, int backEnd)
{
    if(preEnd - preBegin != midEnd - midBegin) return false;
    if(preEnd < preBegin) return true;

    pBack[backEnd] = pPre[preBegin];

    //find the mid pos
    int preLength = -1; //preOrderSequence[preBegin]在中序序列中与中序序列开头的距离
    for(int i= midBegin; i<=midEnd; ++i)
    {
        if(pMid[i] == pPre[preBegin])
        {
            preLength = i - midBegin;
            break;
        }
    }
    if(preLength == -1) return false; /*中序序列中没找到对应的字符*/

    return _CalcBackOrderSequence(pPre, preBegin + 1, preBegin + preLength,
                                  pMid, midBegin, midBegin + preLength - 1,
                                  pBack, backBegin, backBegin + preLength-1) &&
           _CalcBackOrderSequence(pPre, preBegin + preLength + 1, preEnd,
                                  pMid, midBegin + preLength+1, midEnd,
                                  pBack, backBegin + preLength,  backEnd-1);
}
char* CalcBackSequence(const char *pPre, const char *pMid)
{
    if(pPre == NULL || pMid == NULL)
    {
        fprintf(stderr, "Error CalcBackSequence: null pointer error\n");
        return NULL;
    }

    int preLength = strlen(pPre);
    if(preLength != strlen(pMid))
    {
        fprintf(stderr, "Error CalcBackSequence: two sequence's length is not equal\n");
        return NULL;
    }

    char *pBack = (char *)malloc((preLength + 1) * sizeof(char));
    if(pBack == NULL)
    {
        fprintf(stderr, "Error CalcBackSequence: memory error\n");
        return NULL;
    }
    pBack[preLength] = 0;

    bool ret;
    ret = _CalcBackOrderSequence(pPre, 0, preLength-1, pMid, 0, preLength-1, pBack, 0, preLength-1);
    if(ret == false)
    {
        fprintf(stderr, "Error CalcBackSequece: can not calc the back order sequence, check the parameter\n");
        free(pBack);
        return NULL;
    }
    return pBack;

}
////////////////////////////////////////////////////////////////////////////////
void PreOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        printf("%c", tree->data);
        PreOrderTraverseRecursive(tree->lchild);
        PreOrderTraverseRecursive(tree->rchild);
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//注意这个是非递归遍历二叉树的标准模板，非常简单的模板
//注意点：
//1. 循环条件必须这样写，让判断逻辑简单
//2. 当前结点不为空就变换到左孩子
//3. 否则弹栈，变为右孩子
//4. 栈中存放的是当前结点，而不是当前结点的右孩子
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
////////////////////////////////////////////////////////////////////////////////
void InOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        InOrderTraverseRecursive(tree->lchild);
        printf("%c", tree->data);
        InOrderTraverseRecursive(tree->rchild);
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//和上面的先序的非递归算法极度相似，只是访问元素的位置的位置发生了变化
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
////////////////////////////////////////////////////////////////////////////////
void BackOrderTraverseRecursive(Bitree tree)
{
    if(tree)
    {
        BackOrderTraverseRecursive(tree->lchild);
        BackOrderTraverseRecursive(tree->rchild);
        printf("%c", tree->data);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//后序遍历二叉树的非递归实现，和前面两种的大体结构相同，需要栈的帮助
//区别的地方在于：
//1. 栈中保存的元素除了结点的指针还有结点压栈的次数
//2. 遍历时当前结点不为空时需要将当前item的压栈次数增加一次再压栈
//3. 必须在弹栈时才能访问，且必须是弹第二次的时候;
//4. 弹一次的时候需要换为右孩子，弹两次的时候继续弹栈（当前结点置为空）
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
////////////////////////////////////////////////////////////////////////////////
//
//按照层次遍历二叉树，需要一个队列的帮助
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

////////////////////////////////////////////////////////////////////////////////
//
//按照层次遍历二叉树，且每层都要分行显示
struct QueueItem
{
    BitreeNode *pNode;
    int layer;
};
void LayerOrderTraverse2(Bitree tree)
{
    std::queue<QueueItem> queue;
    QueueItem item;
    int currentLayer = 0;
    BitreeNode *pCurrentNode;

    item.pNode = tree;
    item.layer = 0;
    queue.push(item);
    while(!queue.empty())
    {
        item = queue.front();
        queue.pop();
        pCurrentNode = item.pNode;
        if(currentLayer != item.layer)
        {
            currentLayer = item.layer;
            printf("\n");
        }

        if(item.pNode)
        {
            printf("%c", item.pNode->data);
            item.layer++;
            if(pCurrentNode->lchild)
            {
                item.pNode = pCurrentNode->lchild;
                queue.push(item);
            }
            if(pCurrentNode->rchild)
            {
                item.pNode = pCurrentNode->rchild;
                queue.push(item);
            }
        }
    }
    return;
}
////////////////////////////////////////////////////////////////////////////////
//
//遍历指定的一行，根是第0行
void TraverseLayer(Bitree tree, int layer)
{
    std::queue<QueueItem> queue;
    QueueItem item;
    BitreeNode *pCurrentNode;

    item.pNode = tree;
    item.layer = 0;
    queue.push(item);
    while(!queue.empty())
    {
        item = queue.front();
        queue.pop();
        pCurrentNode = item.pNode;

        if(item.pNode)
        {
            if(item.layer == layer)
            {
                printf("%c", item.pNode->data);
            }
            else if(item.layer < layer)
            {
                item.layer++;
                if(pCurrentNode->lchild)
                {
                    item.pNode = pCurrentNode->lchild;
                    queue.push(item);
                }
                if(pCurrentNode->rchild)
                {
                    item.pNode = pCurrentNode->rchild;
                    queue.push(item);
                }
            }
        }
    }
    return;
}
////////////////////////////////////////////////////////////////////////////////
//
//返回树的高度
int TreeDepth(Bitree tree)
{
    if(tree == NULL)
        return 0;
    int leftDepth  = TreeDepth(tree->lchild);
    int rightDepth = TreeDepth(tree->rchild);

    return leftDepth > rightDepth? leftDepth + 1: rightDepth + 1;
}

////////////////////////////////////////////////////////////////////////////////
//
//搜寻两个结点的最近共同父母
//NearestParent是接口函数，指定树跟tree, 和两个孩子即可
//_NearestParent是功能函数，增加了一个参数result，如果找到了，结果在其中
//_NearestParent返回值表示first和second有几个是它的孩子
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

////////////////////////////////////////////////////////////////////////////////
void _LongestPath(Bitree tree, int *pLength, int *pLeftDepth, int *pRightDepth)
{
	if(tree == NULL)
	{
		*pLength = -1;
		*pLeftDepth = -1;
		*pRightDepth = -1;
		return;
	}

	int lLeftDepth, lRightDepth, rLeftDepth, rRightDepth, leftLength, rightLength;

	_LongestPath(tree->lchild, &leftLength, &lLeftDepth, &lRightDepth);
	_LongestPath(tree->rchild, &rightLength, &rLeftDepth, &rRightDepth);

	*pLeftDepth = lLeftDepth > lRightDepth ? lLeftDepth + 1 : lRightDepth + 1;
	*pRightDepth = rLeftDepth > rRightDepth ? rLeftDepth + 1 : rRightDepth + 1;

	*pLength = *pLeftDepth + *pRightDepth;
	if(*pLength < leftLength)
	{
		*pLength = leftLength;
	}
	if(*pLength < rightLength)
	{
		*pLength = rightLength;
	}
	return;
}
int LongestPath(Bitree tree)
{
	int leftDepth, rightDepth, length;

	_LongestPath(tree, &length, &leftDepth, &rightDepth);

	return length;
}
