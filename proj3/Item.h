// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;


class  Item
{
    private:
        string name;
        string detail;
    public:
        Item();
        Item(string name, string detail);
        string getname();
        string getDetail();
        void setName(string nm);
        void setDetail(string det);



};


#endif