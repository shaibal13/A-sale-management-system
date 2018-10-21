#ifndef SEARCHPRODUCT_CPP
#define SEARCHPRODUCT_CPP

#include<iostream>
#include<fstream>
#include"SearchProduct.h"
using namespace std;
template<class Item>

SearchProduct<Item>::SearchProduct()
{

}

template<class Item>
void SearchProduct<Item>::Search(string name[],int size)
{

       Ad.getProduct(name,size);

}








#endif
