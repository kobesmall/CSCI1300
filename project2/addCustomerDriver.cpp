// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 9 (7 points): addCustomer


#include "Customer.h"
#include <iostream>
#include <string>
#include <locale>

int addCustomer(string customerName, Customer customers[], int numProducts, int numCustomersStored, int customersArrSize){

    int emptyArr[numProducts];

    if(numCustomersStored >= customersArrSize){             //check initial condition
        return -2;
    }
    if(customerName.empty()){                                  //check if customer name is empty
        return -1;
    }

    for( int i =0; i< numCustomersStored; i++){                 //loop over customer array to see if naem already present

        if(customers[i].getCustomerName() == customerName ){
            return -1;
        }

    }

    customers[numCustomersStored+1]= Customer(customerName, emptyArr, numProducts);         //add customer to array and increase num of customers
    numCustomersStored++;
    return numCustomersStored;

}



int main() {
/*
Customer customers[1];
int numProducts = 50;
int customersArrSize = 1;
customers[0].setCustomerName("Ninja");
// Add 5 purchases made by the customer “Ninja”
for(int i=0; i < 5; i++) {
customers[0].setPurchasesAt(i, i);
}
int numCustomersStored = 1;
int val = addCustomer("Knuth", customers, numProducts,
numCustomersStored, customersArrSize);
cout<< val << endl;
*/

/*
Customer custo[10];
customersArrSize = 10;
numCustomersStored = 0;
numProducts = 50;
val = addCustomer("Knuth", custo, numProducts,
numCustomersStored, customersArrSize);
cout << val << endl;
*/

Customer customers[10];
int customersArrSize = 10;
int numProducts = 5;
customers[0].setCustomerName("Knuth");
customers[1].setCustomerName("Richie");
// Add 5 purchases
for(int i=0; i<numProducts; i++) {
customers[0].setPurchasesAt(i, i);
customers[1].setPurchasesAt(i, 5-i);
}
int numCustomersStored = 2;
int val = addCustomer("Ninja", customers, 5, numCustomersStored, customersArrSize) ;
cout<<"Total number of customers in the array:"<<val<<endl;

for(int i=0; i<numCustomersStored; i++) {
cout<<customers[i].getCustomerName()<<" - ";
for(int j=0; j<5; j++) {
cout<<customers[i].getPurchasesAt(j)<<", ";
}
cout<<endl;
}


    return 0;
}