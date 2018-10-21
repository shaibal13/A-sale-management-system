#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP

#include"UnsortedType.h"
using namespace std;

UnsortedType::UnsortedType(){

   length=0;
   listData=NULL;
   currentPos=NULL;
   //cout<<"HI"<<endl;


}

bool UnsortedType::IsFull() const
{
    NodeType *location;
    try
    {
       location=new NodeType;
       delete location;
       return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }

}
bool UnsortedType::IsEmpty()const
{
    return (listData==NULL);
}

int UnsortedType::GetLength() const
{
    return length;
}

void UnsortedType::MakeEmpty()
{
    NodeType *tempPtr;
    while(listData!=NULL)
    {
        tempPtr=listData;
        listData=listData->next;
        delete tempPtr;
    }
    length=0;
}

void UnsortedType::InsertItem(ItemType item)
{

    NodeType *location;
    location=new NodeType;
    location->next=listData;
    location->info=item;
    listData=location;
    length++;
}

ItemType UnsortedType::GetItem(ItemType &item, bool &found)
{
    bool moreToSearch;
    NodeType *location;

    location=listData;
    found=false;
    moreToSearch=(location!=NULL);
    while(moreToSearch && (!found))
    {
        switch(item.ComparedTo(location->info))
        {
            case LESS:
            case GREATER:
                location=location->next;
                moreToSearch=(location!=NULL);
                break;
            case EQUAL:
                found=true;
                item=location->info;
                break;
        }
    }
    return item;

}

void UnsortedType::deleteItem(ItemType item)
{
    NodeType* location=listData;
    NodeType* tempLocation;

    if(item.ComparedTo(listData->info)==EQUAL){

        tempLocation=location;
        listData=listData->next;

    }
    else{

        while(item.ComparedTo((location->next)->info)!=EQUAL)

            location=location->next;

            tempLocation=location->next;
            location->next=(location->next)->next;

    }
    delete tempLocation;
    length--;
}

void UnsortedType::ResetList()
{
    currentPos=NULL;
}

ItemType UnsortedType::GetNextItem()
{
    ItemType item;
    if(currentPos==NULL)
        currentPos=listData;
    else
        currentPos=currentPos->next;
    item=currentPos->info;
    return item;
}

UnsortedType:: ~UnsortedType()
{
    NodeType *tempPtr;

    while(listData!=NULL)
    {
        tempPtr=listData;
        listData=listData->next;
        delete tempPtr;
    }
}

#endif // UNSORTEDTYPE_CPP


