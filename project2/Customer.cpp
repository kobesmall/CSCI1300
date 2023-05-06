// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 - Problem 6 (8 points): Customer Class

#include <iostream>
#include "Customer.h"

using namespace std;


Customer::Customer(){

    customerName = "";

    for (int i = 0; i < size; i++){
        purchases[i] = 0;
    }
}

Customer::Customer(string custNm, int purch[], int sz){
        customerName = custNm;

        for (int i =0; i < sz; i++){

            purchases[i] = purch[i];

        }
        
        for (int x = sz; x < size; x++){

            purchases[x] = 0;
        }
    
}

string Customer::getCustomerName(){
    return customerName;
}

void Customer::setCustomerName(string nm){
    customerName = nm;
}

int Customer::getPurchasesAt(int index){
    if( index > size || index < 0){
        return -1;
    }
    return purchases[index];

}


bool Customer::setPurchasesAt(int index, int value){
    if(index < size && index >= 0 && value > 0){
    purchases[index] = value;
    return true;
    }
    return false;
}


int Customer::getTotalPurchaseCount(){

    int total = 0;

    for (int i = 0; i < size; i++){
        total += purchases[i];
    }

    return total;
}

int Customer::getNumUniquePurchases(){

    int count = 0;


    for (int i =0; i< size; i++){

        if(purchases[i] > 0){
            count ++;
        }
    }
    return count;
}

int Customer::getSize(){
    return size;
}