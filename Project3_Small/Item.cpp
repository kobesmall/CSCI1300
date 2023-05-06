// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#include <iostream>
#include "Item.h"


using namespace std;


Item::Item(){                                       //constructors
    name = "";
    detail = "";
}

Item::Item(string nm, string dt){
    name = nm;
    detail = dt;

}

string Item::getDetail(){                          //getters and setters
    return detail;
}

string Item::getname(){
    return name;
}

void Item::setName(string nm){
    name = nm;
}

void Item::setDetail(string det){
    detail = det;
}