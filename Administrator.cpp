#ifndef ADMINISTRATOR_CPP
#define ADMINISTRATOR_CPP
#include<iostream>
#include<fstream>
#include <ctime>
#include <sstream>
#include"Administrator.h"
using namespace std;

template<class Item>
Administrator<Item>::Administrator()
{

}

template<class Item>
void Administrator<Item>::AddProduct(ItemType item)
{
    uns.InsertItem(item);
    ItemType item1;
    bool found;
    ifstream in;
    in.open("Product.txt");
    string pc,nm;
    int pr,qn;
    while(in>>pc && in>>nm && in>>pr)
    {
        item1.Initialize(pc,nm,pr);
        uns.InsertItem(item1);
    }
    ofstream out;
    out.open("Product.txt");
    uns.GetNextItem().Print(out);
}

template <class Item>
int Administrator<Item>::getDate()
{
    time_t now = time(0);
    struct tm * timenow = localtime(&now);
    return timenow->tm_mday;
}

template <class Item>
void Administrator<Item>::TotalSale()
{
    int day = getDate();
    stringstream ss;
    ss << day;
    string str = ss.str();
    ifstream in;
    in.open(("TS"+str+".txt").c_str());
    in >> day;
    cout << "Total Sale for Today is " << day << endl;
}

#endif
