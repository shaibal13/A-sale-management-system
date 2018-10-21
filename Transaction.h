#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const double Vat_Amount=6;
template<class Item>
class Transaction
{
public:
    Transaction();
    void Time();
    double Vat(double);
    double Discount(double,bool);
    void productSale(string[],string[],double[],int[],int);
    double TotalAmount(double,bool);
    void PrintSlip(double,double,bool);
    double AmountChange(double,double,bool);
    int getDate();
    void OpenNote();
    void SaveToFile(string[],string[],double[],int[],double[],double,bool,int);
    void TotalToday(double);

private:
    int SaleNo = 1;
    double totalNow = 0;
    bool NoteOpen;
    ofstream outFile;

};
#include"Transaction.cpp"
#endif // TRANSACTION_H_INCLUDED
