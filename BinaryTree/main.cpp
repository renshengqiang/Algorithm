#include "Bitree.h"
#include <stdio.h>

int main()
{
    const char *preOrder = "ABEHGCDFIJ";
    const char *inOrder = "BHEGADCIFJ";

    Bitree tree = InitTree(preOrder, inOrder);

    PreOrderTraverseRecursive(tree);
    printf("\n");

    PreOrderTraverseNonRecursive(tree);
    printf("\n");

    InOrderTraverseRecursive(tree);
    printf("\n");
    
    InOrderTraverseNonRecursive(tree);
    printf("\n");

    BackOrderTraverseRecursive(tree);
    printf("\n");

    BackOrderTraverseRecursive(tree);
    printf("\n");

    LayerOrderTraverse(tree);
    printf("\n");

    printf("tree depth: %d\n", TreeDepth(tree));

    BitreeNode *parent = NearestParent(tree, 'D', 'J');
    if(parent)
        printf("nearest parent: %c\n", parent->data);
    return 0;
}
