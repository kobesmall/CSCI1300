// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Question 1 (5 points): City Class

#include "City.h"
#include <iostream>


using namespace std;

int main(){


string name = "Omaha";
int population = 475862;
int squareMileage = 145;
City c4 = City(name, population,squareMileage);
cout << "City name: " << c4.getName() << endl;
cout << "Population: " << c4.getPopulation() <<endl;
cout << "Size: " << c4.getSquareMileage() << " square miles" << endl;
cout << "Population density: " <<c4.getPopulationDensity() << " people persquare mile" << endl;

City c5 = City();
cout << "City name: " << c5.getName() << endl;
cout << "Population: " << c5.getPopulation() <<endl;
cout << "Size: " << c5.getSquareMileage() << " square miles" << endl;
cout << "Population density: " <<c5.getPopulationDensity() << endl;

cout<< "set functions" << endl;
c5.setName("denver");
c5.setPopulation(56);
c5.setSquareMileage(3);
cout << endl;

cout << "City name: " << c5.getName() << endl;
cout << "Population: " << c5.getPopulation() <<endl;
cout << "Size: " << c5.getSquareMileage() << " square miles" << endl;
cout << "Population density: " <<c5.getPopulationDensity() << endl;
return 0;
}