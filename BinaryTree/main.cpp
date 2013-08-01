#include "Bitree.h"
#include <stdio.h>

int main()
{
    const char *preOrder = "ABEHGCDFIJ";
    const char *inOrder = "BHEGADCIFJ";

    Bitree tree = InitTree(preOrder, inOrder);

    printf("back order: %s\n", CalcBackSequence(preOrder, inOrder));

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

    LayerOrderTraverse2(tree);
    printf("\n");

    printf("Layer0: ");
    TraverseLayer(tree, 0);
    printf("\n");

    printf("Layer3: ");
    TraverseLayer(tree, 3);
    printf("\n");

    printf("Layer5: ");
    TraverseLayer(tree, 5);
    printf("\n");

    printf("tree depth: %d\n", TreeDepth(tree));

    BitreeNode *parent = NearestParent(tree, 'D', 'J');
    if(parent)
        printf("nearest parent: %c\n", parent->data);
    return 0;
}
