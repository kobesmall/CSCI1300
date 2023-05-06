// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Problem 2 (5 points): maxPopulation

#include "City.h"
#include <iostream>


using namespace std;

int maxPopulation(City cities[], int size){

double maxPop = 0.0;                        //var for max populaiton
int maxI = 0;                               //var for index of city with max pop

    if(size < 1){                           //condition to check if array empty
        return -1;
    }

    for(int i = 0; i < size; i++){                  //loop over elements in array
        if(cities[i].getPopulation() > maxPop){      //condititon to check population of city in the array with previous max value
            maxPop = cities[i].getPopulation();
            maxI = i;                                   //store index of city with max pop
        }   
    }


return maxI;
}

int main(){


City cities[5];
cities[0] = City("Denver", 705576, 155);
cities[1] = City("San Jose", 1028000, 181);
cities[2] = City("Omaha", 475862, 145);

int index = maxPopulation(cities, 3);
cout << cities[index].getName() << endl;
cout << cities[index].getPopulation() << endl;
cout << cities[index].getPopulationDensity() << endl;;


City emptyArray[3];
int inde = maxPopulation(emptyArray, 0);
cout << inde << endl;

  return 0;  
}
