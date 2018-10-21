#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include"ItemType.h"
using namespace std;
const int MAX_ITEMS=5;

struct NodeType
{
    ItemType info;
    NodeType *next;

};

class UnsortedType
{

    public:
       UnsortedType();
       ~UnsortedType();
       void MakeEmpty();
       bool IsFull() const;
       bool IsEmpty()const;
       int GetLength() const;
       ItemType GetItem(ItemType&,bool&);
       void InsertItem(ItemType);
       void deleteItem(ItemType);
       void ResetList();
       ItemType GetNextItem();
    private:
        NodeType *listData;
        int length;
        NodeType *currentPos;
};

#endif // UNSORTEDTYPE_H_INCLUDED
