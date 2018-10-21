#ifndef SALESMAN_CPP
#define SALESMAN_CPP
#include"Salesman.h"

using namespace std;

template <class Item>
Salesman<Item>::Salesman()
{

}

template <class Item>
void Salesman<Item>::AddProduct()
{
    ItemType item1;
    ifstream in;
    in.open("Product.txt");
    string pc,nm;
    int pr,qn;
    while(in>>pc && in>>nm && in>>pr)
    {
        item1.Initialize(pc,nm,pr);
        UNS.InsertItem(item1);
    }
    in.close();

}

template <class Item>
void Salesman<Item>::SaleProduct()
{
    int count=0;
    string product[100];
    string str;
    cout<<endl;
    while(str!="QUIT")
    {
        cin>>str;
        if(str=="NEW")
        {
            count=0;
            while(str!="FINISH")
            {
                cout<<"Enter The Product Name:::";
                cin >> str;
                if(str=="FINISH")
                {
                    ;
                }
                else
                {
                    product[count]=str;
                    count++;
                }
            }
            getProduct(product,count);
        }

    }
}

template <class Item>
void Salesman<Item>::getProduct(string productList[], int size)
{
    ItemType it;
    bool found[size];
    string productCode[size];
    double price[size];
    int quantity[size];
    for(int i=0; i<size; i++)
    {
        it.Initialize("",productList[i],0);
        UNS.GetItem(it,found[i]);
        if(found[i]==true)
        {
            productCode[i] = it.pro.ProductCode;
            price[i] = it.pro.price;
            cout << it.pro.ProductCode << " " << it.pro.name << endl;
            cout << "Enter Quantity:: ";
            cin >> quantity[i];
        }
        else
        {
            cout << productList[i] << " Not Found" << endl;
        }

    }
    TR.productSale(productCode,productList,price,quantity,size);
}

#endif
