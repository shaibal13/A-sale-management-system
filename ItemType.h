#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include<iostream>
#include<fstream>
using namespace std;

enum RelationType{LESS,GREATER,EQUAL};
struct ProductInfo
{
    string ProductCode;
    string name;
    int price;
};
class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(ofstream&) const;
    void Initialize(string,string,int);
    ProductInfo pro;

private:

};

#endif // ITEMTYPE_H_INCLUDED
