#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct HuffmanNode
{
    int value;
    float weight;
    struct HuffmanNode *lchild, *rchild;
};
class Comparator
{
public:
    bool operator()(const HuffmanNode& lhs, const HuffmanNode &rhs)
    {
        return lhs.weight > rhs.weight;
    }
};

//Name: _Insert
//Desc: insert a new node into array, which has n elements
void _Insert(HuffmanNode array[], int n, HuffmanNode *lchild, HuffmanNode *rchild)
{
    if(n<0 || lchild == NULL || rchild == NULL) return;

    //find the insertion pos
    int i;
    float weight = lchild->weight + rchild->weight;
    for(i = n - 1; i >= 0; --i)
    {
        if(array[i].weight < weight) 
        {
            array[i+1].value = array[i].value;
            array[i+1].weight = array[i].weight;
            array[i+1].lchild = array[i].lchild;
            array[i+1].rchild = array[i].rchild;
        }
        else break;
    }
    array[i+1].value = 0;
    array[i+1].weight = weight;
    array[i+1].lchild = lchild; 
    array[i+1].rchild = rchild;
}

//Name: Make a Huffman Tree to implement coding
//Desc: return the root of the tree;
HuffmanNode* MakeHuffmanTree(HuffmanNode *array, int n)
{
    if(n<1) return NULL;
    //first, sort the array in assceding order
    sort(array, array+n, Comparator());
   
    //begin make tree
    int leftNum = n;
    HuffmanNode *node1 = NULL, *node2 = NULL;
    while(leftNum > 1)
    {
        node1 = new HuffmanNode();
        node2 = new HuffmanNode();
        node1->value = array[leftNum-1].value;
        node1->weight = array[leftNum-1].weight;
        node1->lchild = array[leftNum-1].lchild;
        node1->rchild = array[leftNum-1].rchild;
        node2->value = array[leftNum-2].value;
        node2->weight = array[leftNum-2].weight;
        node2->lchild = array[leftNum-2].lchild;
        node2->rchild = array[leftNum-2].rchild;
        _Insert(array, leftNum - 2, node1, node2);
        leftNum--;
    }
   
    HuffmanNode *root = new HuffmanNode();
    root->value = array[0].value;
    root->weight = array[0].weight;
    root->lchild = array[0].lchild;
    root->rchild = array[0].rchild;
    return root;
}

void PrintCodeing(HuffmanNode *root, string str)
{
    if(root == NULL) return;
    else if(root->lchild == NULL && root->rchild == NULL)
    {
        cout << root->value << " " << str << endl;
        return;
    }
    PrintCodeing(root->lchild, str+'0');
    PrintCodeing(root->rchild, str+'1');
}
int main()
{
    int n;
    HuffmanNode *array = NULL;
    HuffmanNode *root = NULL;

    cout << "input the number of the number to be coding:" << endl;
    cin >> n;

    array = new HuffmanNode[n];
    cout << "input the values:" << endl;
    for(int i=0; i<n; ++i)
    {
        cin >> array[i].value;
        array[i].lchild = array[i].rchild = NULL;
    }
    cout << "input the weights:" << endl;
    for(int i=0; i<n; ++i)
    {
        cin >> array[i].weight;
    }

    root = MakeHuffmanTree(array, n);
    PrintCodeing(array, "");
    return 0;
} 
