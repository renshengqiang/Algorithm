/*************************************************************************
	> File Name: TraverByLayer.c
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年05月09日 星期四 23时48分56秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
struct TreeNode{
	int value;
	struct TreeNode *lchild, *rchild, *next;
};
void init(struct TreeNode **root)
{
	struct TreeNode *node[4];
	*root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	(*root)->value = 1;
	(*root)->next = NULL;
	for(int i=0; i<4; ++i)
	{
		node[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		node[i]->value = i + 2;
		node[i]->lchild = node[i]->rchild = node[i]->next = NULL;
	}
	(*root)->lchild = node[0];
	(*root)->rchild = node[1];
	node[1]->lchild = node[2];
	node[1]->rchild = node[3];
}
void makelist(struct TreeNode *root)
{
	struct TreeNode *p1, *p2;
	p1 = root;
	while(p1)
	{
		printf("%d ", p1->value);
		//p2 = p1->next
		if(p1->lchild) p2 = p1->lchild;
		else p2 = p1->rchild;
		
		if(p1->lchild && p1->rchild) p1->lchild->next = p1->rchild;

		if(p1->next == NULL) p1->next = p2;
		p1 = p1->next;
	}
	printf("\n");
}
int main()
{
	struct TreeNode *root;
	
	init(&root);
	makelist(root);
	
	while(root)
	{
		printf("%d ", root->value);
		root = root->next;
	}
	printf("\n");

}
