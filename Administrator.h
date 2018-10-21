#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include<iostream>
#include<fstream>
#include"UnsortedType.h"
#include "Transaction.h"
using namespace std;

template<class Item>
class Administrator
{
public:
    Administrator();
    void AddProduct(ItemType);
    void AmountSale(int);
    void UpdateProduct();
    void TotalSale();
    int getDate();

private:
    UnsortedType uns;
    Transaction<Item> tr;
};

#include"Administrator.cpp"
#endif // ADMINISTRATOR_H
