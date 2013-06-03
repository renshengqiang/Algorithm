#ifndef _QTL_MAP_H
#define _QTL_MAP_H
#include <AVLTree.h>
namespace QTL{
    template <typename KeyType, typename ValueType>
    struct Pair{
        Pair(){}
        Pair(const KeyType key, const ValueType value){ first = key; second = value;}
        KeyType     first;
        ValueType   second;
    };
    template <typename KeyType, typename ValueType>
    class Map{
        public:
            struct iterator{
                iterator();
                iterator(typename AVLTree<KeyType, ValueType>::BSTreeNode *p);
                iterator& operator++();
                iterator& operator--();
                //Pair<KeyType, ValueType>& operator*();
                Pair<KeyType, ValueType>* operator->();
                bool operator!=(const iterator& rhs);
                bool operator==(const iterator& rhs);
            private:
                typename AVLTree<KeyType, ValueType>::BSTreeNode *pNode;
            };

            Pair<iterator, bool> Insert(const Pair<KeyType, ValueType>& pair);
            //KeyType& operator[](const KeyType& key);
            iterator find(const KeyType& key);
            iterator begin();
            iterator end();
        private:
            AVLTree<KeyType, ValueType> mAVLTree;
    };
}
#include <Map.cpp> 
#endif
