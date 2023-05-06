// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 8 (5 points): getPurchasedQuantity

#include "Customer.h"
#include "Product.h"
#include <iostream> 
#include <fstream>
#include <iostream>

using namespace std;



int getPurchasedQuantity(string customerName, string productName, Customer customers[], Product products[], int numCust, int numProd){

int index = -3;
int numPurchases = -3;

for (int i = 0; i < numProd; i++){                      //loop through product arrray

    if(products[i].getName() == productName){           //look for index of search product and store
        index = i;
    }

}
if(index == -3){                                        //condition to check if there was a product or not
    return -3;
}

for (int x = 0; x < numCust; x++){                      //loop through customer array 

    if( customers[x].getCustomerName() == customerName){            //look for customer with name of customer were looking for
            numPurchases = customers[x].getPurchasesAt(index);      //call member function at index of product to return times purchased
    }   
}

return numPurchases;

}



int main(){

    //Creating 3 products
Product products[3];
//Setting product name and price for product 1
products[0].setName("Garden Gnome");
products[0].setPrice(2.5);
//Setting product name and price for product 2
products[1].setName("Cat Food");
products[1].setPrice(10);
//Setting product name and price for product 3
products[2].setName("Lawn Mower");
products[2].setPrice(180);

//Creating 2 customers
Customer customers[2];
//Setting customerName and purchases for Customer1
customers[0].setCustomerName("Customer1");
customers[0].setPurchasesAt(0,1);
customers[0].setPurchasesAt(1,4);
customers[0].setPurchasesAt(2,2);
//Setting customerName and purchases for Customer1
customers[1].setCustomerName("Customer2");
customers[1].setPurchasesAt(0,0);
customers[1].setPurchasesAt(1,5);
customers[1].setPurchasesAt(2,2);


cout << getPurchasedQuantity("Customer1", "Garden Gnome",customers, products, 2, 3) << endl;

cout << getPurchasedQuantity("A Ghost", "Garden Gnome",customers, products, 2, 3) << endl;;

cout << getPurchasedQuantity("Customer1", "Speed Cola",customers, products, 2, 3) << endl;
}