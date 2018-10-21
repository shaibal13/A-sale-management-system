#ifndef ITEMTYPE_CPP
#define ITEMTYPE_CPP
#include"ItemType.h"
#include<iostream>
#include<fstream>
using namespace std;

ItemType::ItemType()
{
   pro.ProductCode=" ";
   pro.name=" ";
   pro.price=0;
}

RelationType ItemType::ComparedTo(ItemType otherItem)const
{
    if (pro.name<otherItem.pro.name)
    {
        return LESS;
    }
    else if(pro.name>otherItem.pro.name)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(string productCode,string na,int pr)
{
    pro.ProductCode=productCode;
    pro.name=na;
    pro.price=pr;
}

void ItemType::Print(ofstream& outFile) const
{
    outFile << pro.ProductCode << "  " <<pro.name<< " " <<pro.price<< endl;
}

#endif // ITEMTYPE_CPP

