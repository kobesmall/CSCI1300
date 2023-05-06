// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 10 (10 points): getCustomerStats

#include "Customer.h"
#include <iostream>
#include <string>
#include <locale>
#include <iomanip> 

using namespace std;


int getCustomerStats( string customerName, Customer customers[], int numCust, int numProd){

    int index = -1;

    for (int i =0 ; i < numCust; i++){

        if(customers[i].getCustomerName() == customerName){
            index = i ;
        }
    }


    if(index == -1){
        cout << customerName << " does not exist" << endl;
        return -3;
    }


    if(customers[index].getTotalPurchaseCount() ==0){
        cout<< customers[index].getCustomerName() << " has not purchased any products" << endl;
        return 0 ;
    }

    cout << customers[index].getCustomerName() << " purchased " << customers[index].getNumUniquePurchases() << " products" << endl;
    cout << customers[index].getCustomerName() << setprecision(2)<< fixed <<  "'s average purchased quantity was " << (double) customers[index].getTotalPurchaseCount() / customers[index].getNumUniquePurchases() << endl;
    return 1;
}

int main(){


    //Creating 3 customers
Customer customers[3];
//Setting customerName and purchases for Customer1
customers[0].setCustomerName("Customer1");
customers[0].setPurchasesAt(0,1);
customers[0].setPurchasesAt(1,4);
customers[0].setPurchasesAt(2,2);
//Setting customerName and purchases for Customer2
customers[1].setCustomerName("Customer2");
customers[1].setPurchasesAt(0,0);
customers[1].setPurchasesAt(1,5);
customers[1].setPurchasesAt(2,3);
//Setting customerName and purchases for Customer3
customers[2].setCustomerName("Customer3");
customers[2].setPurchasesAt(0,0);
customers[2].setPurchasesAt(1,0);
customers[2].setPurchasesAt(2,0);

getCustomerStats("Customer1", customers, 3, 3);
}