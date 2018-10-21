#include <iostream>
#include<fstream>
#include<ctime>
#include"ItemType.h"
#include"UnsortedType.h"
#include"Administrator.h"
#include"Salesman.h"

using namespace std;
int DateNow()
{
    time_t now = time(0);
    struct tm * timenow = localtime(&now);
    return(timenow->tm_mday);
}
int main()
{
    ItemType it;
    UnsortedType un;
    Administrator<string>ad;
    Salesman<string>s;
    ifstream in;
    in.open("Product.txt");
    ifstream inFile;
    inFile.open("id&pass.txt");
    ofstream outFile;
    outFile.open("Time.txt");

    int n;
    cout << "\t\tHello! WELCOME TO Point of Sale System" << endl
         << "\t\t**************************************" << endl
         << "Enter Date: ";
    cin >> n;
    while(n!=DateNow())
    {
        cout << "Date is Not Correct. Please Check & Enter Again ";
        cin >> n;
    }
    string id[2],pass[2];
    int i=0;
    while(inFile>>id[i])
    {
        inFile>>pass[i];
        i++;
    }
    bool found=false;
    while(found!=true)
    {
        string idq,passq;
        cout<<"Enter The ID::";
        cin>>idq;
        cout<<endl;
        cout<<"Enter The Pass::";
        cin>>passq;
        cout<<endl;
        int j=0;
        for(j=0; j<2; j++)
        {
            if(id[j]==idq &&pass[j]==passq)
            {
                cout << "*******PASSWORD MATCH********" << endl;
                cout << "Enter NEW , FINISH or QUIT" << endl
                     << "NEW = New Customer" << endl
                     << "FINISH = CheckOut Customer" << endl
                     << "QUIT = Close Selling" << endl
                     <<" ENTER YOUR OPTION>>>";

                s.AddProduct();
                s.SaleProduct();
                found=true;
                break;
            }
            else
            {
                found=false;
            }

        }
        if(found==false)
            cout << "Invalid Input.Please Check ID & Password." << endl << endl;

    }





    return 0;
}
