// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 1 (1 point): Product Class - 

#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>


using namespace std;


class Product
{
private:
    string name;
    double price;       //private data members
    string category;

public:
    Product();
    Product(string name, double price, string category);        //declaring public functions and constructors
    string getName();
    void setName(string);
    double getPrice();
    void setPrice(double);
    string getCategory();
    void setCategory(string);


};

#endif
