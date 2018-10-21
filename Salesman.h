#ifndef SALESMAN_H
#define SALESMAN_H
#include<iostream>
#include<fstream>
#include "UnsortedType.h"
#include "ItemType.h"
#include "Transaction.h"
using namespace std;

template<class Item>
class Salesman
{
public:
    Salesman();
    void AddProduct();
    void SaleProduct();
    void getProduct(string[],int);
private:
    UnsortedType UNS;
    ItemType IT;
    Transaction<Item> TR;

};
#include"Salesman.cpp"
#endif // SALESMAN_H
