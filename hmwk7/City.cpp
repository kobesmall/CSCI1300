// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Question 1 (5 points): City Class

#include <iostream>
#include "City.h"     
     

using namespace std; 
     
City::City(){                               //implement defualt constructor
         cityName = "";
         population = 0; 
         squareMileage = 0;
     }
City::City(string cityN, int pop, int sM){      //implement param constructor
         cityName = cityN;
         population = pop;
         squareMileage = sM;
     }

string City::getName(){                         //implement functions as defined in header file
        return cityName;    
    }

void City::setName(string name){
        cityName = name;
    }

int City::getPopulation(){
    return population;
}
void City::setPopulation(int p){
    population = p;
}
int City::getSquareMileage(){
    return squareMileage;
}
void City::setSquareMileage(int sm){
    squareMileage = sm;
}
double City::getPopulationDensity(){
    if(squareMileage==0){                   //avoid divid by 0 error
        return 0;
    }
    double ans = (double) population / squareMileage;
    return ans;
}
