// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Problem 3 (8 points): Product Class

#include "Product.h"
#include <iostream>


using namespace std;

int main(){

string name = "bread";
double price = 9.6;
string category = "food";
Product bread(name,price,category);
cout << "product name: " << bread.getName() << endl;
cout << "product price: $" << bread.getPrice() << endl;
cout << "product category: " << bread.getCategory() << endl;

cout << "set functions"<< endl;
bread.setPrice(6.7);
bread.setCategory("soft");
bread.setName("dough");
cout << endl;

cout << "product name: " << bread.getName() << endl;
cout << "product price: $" << bread.getPrice() << endl;
cout << "product category: " << bread.getCategory() << endl;

cout << endl;
Product nm = Product();
cout << "product name: " << nm.getName() << endl;
cout << "product price: $" << nm.getPrice() << endl;
cout << "product category: " << nm.getCategory() << endl;
return 0 ;

}