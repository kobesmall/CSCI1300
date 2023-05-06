// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 - Problem 6 (8 points): Customer Class


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>


using namespace std;

class Customer
{
private:
    string customerName;
    static const int size = 50;
    int purchases[size];

public:
    Customer();
    Customer(string customerName, int purchases[], int size);
    string getCustomerName();
    void setCustomerName(string nm);
    int getPurchasesAt(int index);
    bool setPurchasesAt(int index, int value);
    int getTotalPurchaseCount();
    int getNumUniquePurchases();
    int getSize();

};




#endif