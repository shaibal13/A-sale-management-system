#ifndef TRANSACTION_CPP
#define TRANSACTION_CPP
#include"Transaction.h"
#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

template<class Item>
Transaction<Item>::Transaction()
{
    totalNow = 0;
    SaleNo = 1;
    NoteOpen = false;
}

template<class Item>
void Transaction<Item>::Time()
{
    time_t now = time(0);
    struct tm * timenow = localtime(&now);
    cout<<"                      "<<timenow->tm_mday<<"/"<<timenow->tm_mon+1<<"/"<<timenow->tm_year+1900<<endl;
    cout<<"                       "<<timenow->tm_hour<<":"<<timenow->tm_min<<":"<<timenow->tm_sec<<endl;
}

template<class Item>
double Transaction<Item>::Vat(double amount)
{

    double vat = ((amount*Vat_Amount)/100.0);
    return vat;
}

template<class Item>
double Transaction<Item>::Discount(double amount,bool ISMember)
{
    double discount;
    if(ISMember==true)
       discount = ((amount*10)/100.0);
    else
        discount =0;

        return discount;
}

template <class Item>
double Transaction<Item>::TotalAmount(double amount,bool found)
{
    if(found==false)
    {
        return(amount+(Vat(amount)));
    }

    if(found==true)
    {
        return (amount-(Discount(amount,true))+Vat(amount));
    }

}

template <class Item>
void Transaction<Item>::TotalToday(double amount)
{
    totalNow+=amount;
    int num = getDate();
    stringstream ss;
    ss << num;
    string str = ss.str();
    ofstream out;
    out.open(("TS"+str+".txt").c_str());
    out << totalNow;
    out.close();
}

template <class Item>
void Transaction<Item>::productSale(string productCode[],string name[], double price[], int quantity[],int size)
{
    double totalPrice = 0;
    double priceT[size];
    int receiveMoney;
    bool member = false;
    for(int i=0;i<size;i++)
    {
        totalPrice+=price[i]*quantity[i];
    }
    cout << "Total: " << totalPrice << endl;
    cout << "Member? (0 = False/1 = True)?? ::::";
    cin >> member;
    cout<<"Total Amount After Discount(member??not)+Vat:::"<<TotalAmount(totalPrice,member)<<endl;
    cout << "Received From Customer:: ";
    cin >> receiveMoney;

    cout << endl << "           Welcome to Point of Sale System!"
         << endl << "-------------------------------------------------------"<<endl;
        Time();
    cout << endl;
    cout<<"PCODE"<<"     NAME"<< "\t\t\tPRICE"<<"    QNTY"<<"\t TOTAL"<<endl;
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        priceT[i] = price[i]*quantity[i];
        cout << productCode[i] << "   " << name[i] << "     \t" << price[i] << " \t " << quantity[i] << " \t " << priceT[i] << endl;
    }
    PrintSlip(totalPrice,receiveMoney,member);
    SaveToFile(productCode,name,price,quantity,priceT,totalPrice,member,size);
}

template <class Item>
int Transaction<Item>::getDate()
{
    time_t now = time(0);
    struct tm * timenow = localtime(&now);
    return timenow->tm_mday;
}

template <class Item>
void Transaction<Item>::OpenNote()
{
    int day = getDate();
    stringstream ss;
    ss << day;
    string str = ss.str();
    outFile.open((str+".txt").c_str());
    NoteOpen = true;
}

template <class Item>
void Transaction<Item>::SaveToFile(string productCode[], string name[], double price[], int quantity[], double priceT[], double totalPrice, bool member, int size)
{

    if(NoteOpen!=true)
    {
        OpenNote();
    }
    outFile << "SP ## SaleNo. " << SaleNo << endl;
    for(int i=0;i<size;i++)
    {
        outFile  << productCode[i] << " " << name[i] << " " << price[i] << " " << quantity[i] << " " << priceT[i] << endl;
    }
    outFile << "Total Price: " << totalPrice << endl;
    outFile << "Vat: " << Vat(totalPrice) << endl;
    outFile << "Discount: " << Discount(totalPrice,member) << endl;
    outFile << "Final Amount: " << TotalAmount(totalPrice,member) << endl;
    SaleNo++;
    outFile << endl << endl;
}

template<class Item>
double Transaction<Item>::AmountChange(double purchaseamount,double receiveamount,bool found)
{
    if(found==true)
    return (receiveamount-TotalAmount(purchaseamount,found));
    else
        return (receiveamount-TotalAmount(purchaseamount,found));
}
template <class Item>
void Transaction<Item>::PrintSlip(double purchaseamount,double receiveamount,bool found)
{
           cout<<endl;
           cout<<endl;
         cout << "              Purchase Amount: TK." << purchaseamount
         << endl << "                  Vat(6%): TK." << Vat(purchaseamount)<<endl;
         if(found==true)
            cout<< "                 Discount: TK." << Discount(purchaseamount,found)<<endl;
         else
            cout<<"                 Discount: TK." << Discount(purchaseamount,found)<<endl;
          cout << "--------------------------------------------------------"
         << endl << "                    Total: TK." << TotalAmount(purchaseamount,found)<<endl;
         double tk = TotalAmount(purchaseamount,found);
         TotalToday(tk);
         cout<<"             Customer Given Amount :  TK"<< receiveamount
         <<endl<<"-------------------------------------------------------"
         <<endl<<"              Change Money Amount :   TK"<<AmountChange(purchaseamount, receiveamount,found)<<endl
         <<endl<<"                        THANK YOU!                     "
         <<endl<<"                     HAVE A NICE DAY!                  "<<endl;
}

#endif
