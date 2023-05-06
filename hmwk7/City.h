// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Question 1 (5 points): City Class



#ifndef CITY_H
#define CITY_H
#include <iostream>

using namespace std;


class  City
{
private:                        //private data 
    string cityName;
    int population ;
    int squareMileage;
public:                         //public method declarations, getters and setters
    City();
    City(string cityN, int pop, int sM);
    string getName();
    void setName(string name);
    int getPopulation();
    void setPopulation(int);
    int getSquareMileage();
    void setSquareMileage(int);
    double getPopulationDensity();

};

#endif