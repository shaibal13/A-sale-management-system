#ifndef SEARCHPRODUCT_H
#define SEARCHPRODUCT_H
#include <iostream>
#include <fstream>
#include"Administrator.h"
using namespace std;

template <class Item>
class SearchProduct
{
public:
    SearchProduct();
    void Search(string[],int);

private:
    Administrator<Item>Ad;
};
#include"SearchProduct.cpp"
#endif // SEARCHPRODUCT_H
