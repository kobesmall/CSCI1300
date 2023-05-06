// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 - Problem 6 (8 points): Customer Class

#include "Customer.h"
#include <iostream>

using namespace std;

int main(){
    string name = "Jim";
    int purchases[] = {2,4,5,0,8,0,5,3,9};
    int size = 9;

    Customer Jim = Customer(name, purchases, size);
    cout << "customer name: " << Jim.getCustomerName() << endl;
    cout << "customer purchases at index 4: " << Jim.getPurchasesAt(4) << endl;
    Jim.setPurchasesAt(4,10);
    cout << "set customer purchases at index 4 to 10 (setPurchaseat): " << Jim.getPurchasesAt(4) << endl;
    cout << "customer total purchase count: " << Jim.getTotalPurchaseCount()<< endl;
    cout << "customer unique purchases: " << Jim.getNumUniquePurchases() << endl;


    Jim.setCustomerName("Jimmy H");
    cout << "customer name (set test): " << Jim.getCustomerName() << endl;
    

    Customer Bob = Customer();
    cout << "customer name (defualt cunstructor test): " << Bob.getCustomerName() << endl;
    cout << "customer total purchase count (defualt constructor test): " << Bob.getTotalPurchaseCount() << endl;
    return 0;
}