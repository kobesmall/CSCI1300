// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 1 (1 point): Product Class - 
#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(){                         //defining all functions and constructors as declared in the header file
    name = "";  
    category = "";
    price = 0.0;
}

Product::Product(string nm, double p, string cat){
    name = nm;
    price = p;  
    category = cat;
}

string Product::getName(){
    return name;
}

void Product::setName(string s){
    name = s;
}

double Product::getPrice(){
    return price;
}

void Product::setPrice(double p){
    price = p;
}

string Product::getCategory(){
    return category;
}

void Product::setCategory(string cat){
    category = cat;
}