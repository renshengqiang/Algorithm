#include "Map.h"
/**
 *Map的目的主要是验证我以前的那个平衡二叉树能够正确的在这里进行工作，这里得出的结论:
1. map的内部数据结构一定是一棵平衡树，若是红黑树则加入一个红黑的因子，若是平衡树，则加入一个平衡因子;
2. 二叉树就一定有左孩子和右孩子指针，同时为了方便平衡很可能会加入一个父亲指针
3. 为了线索化的方便，这些节点一定构成一个中序线索树，线索是一个双向链表结构，可以是循环的，也可以不是。所以树节点中会有另外两个指针，前向指针和后向指针。
4. 此文件实现的功能太简单，有时间再进行修改
 * */
namespace QTL{
template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::iterator::iterator()
{
    pNode = NULL;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::iterator::iterator(typename AVLTree<KeyType, ValueType>::BSTreeNode *p)
{
    pNode = p;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename Map<KeyType, ValueType>::iterator&
Map<KeyType, ValueType>::iterator::operator++()
{
    pNode = pNode->next;
    return *this;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename Map<KeyType, ValueType>::iterator&
Map<KeyType, ValueType>::iterator::operator--()
{
    pNode = pNode->pre;
    return *this;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
Pair<KeyType, ValueType>*
Map<KeyType, ValueType>::iterator::operator->()
{
    return (Pair<KeyType, ValueType>*)(pNode);
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::iterator::operator!=(const Map<KeyType, ValueType>::iterator& rhs)
{
    return pNode!=rhs.pNode;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::iterator::operator==(const Map<KeyType, ValueType>::iterator& rhs)
{
    return pNode == rhs.pNode;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
Pair<typename Map<KeyType, ValueType>::iterator, bool>
Map<KeyType, ValueType>::Insert(const Pair<KeyType, ValueType>& pair)
{
    Pair<typename Map<KeyType, ValueType>::iterator, bool> ret;
    typename AVLTree<KeyType, ValueType>::BSTreeNode *pNode = mAVLTree.Insert(pair.first, pair.second);
    if(pNode == NULL)
    {
        ret.second = false;
    }
    else
    {
        ret.first = typename Map<KeyType, ValueType>::iterator(pNode);
        ret.second = true;
    }
    return ret;
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename Map<KeyType, ValueType>::iterator
Map<KeyType, ValueType>::find(const KeyType& key)
{
    typename AVLTree<KeyType, ValueType>::BSTreeNode *pNode = mAVLTree.Search(key);
    return typename Map<KeyType, ValueType>::iterator(pNode);
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename Map<KeyType, ValueType>::iterator
Map<KeyType, ValueType>::begin()
{
    typename AVLTree<KeyType, ValueType>::BSTreeNode *pNode;

    pNode = static_cast<typename AVLTree<KeyType, ValueType>::BSTreeNode*>(mAVLTree.GetFirstNode());
    return typename Map<KeyType, ValueType>::iterator(pNode);
}
//-----------------------------------------------------------------------------
template <typename KeyType, typename ValueType>
typename Map<KeyType, ValueType>::iterator
Map<KeyType, ValueType>::end()
{
    return typename Map<KeyType, ValueType>::iterator(NULL);
}
}
