// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 3 - Problem 3 ...


#include <iostream>
#include <iomanip>

using namespace std;


int main(){

int students =0;
double cost =0.0;

cout << "Enter the number of students in the school district:"<< endl;
cin >> students;


if(students < 0){
    cout << "Invalid input." << endl;
}
else if (students >= 100 && students <= 199){
    cost = (students * 4.5) - (students * 4.5 * .1);
    cout << "The total cost for buying art kits is $" << fixed << setprecision(2) << cost << endl;
}
else if (students >= 200 && students <= 399){
    cost = (students * 4.5) - (students * 4.5 * .15);
    cout << "The total cost for buying art kits is $" << fixed << setprecision(2) << cost << endl;
}
else if (students >= 400 && students <= 599){
    cost = (students * 4.5) - (students * 4.5 * .2);
    cout << "The total cost for buying art kits is $" << fixed << setprecision(2) << cost << endl;
}
else if (students >= 600 ){
    cost = (students * 4.5) - (students * 4.5 * .25);
    cout << "The total cost for buying art kits is $" << fixed << setprecision(2) << cost << endl;
}
else{
    cost = (students * 4.5);
    cout << "The total cost for buying art kits is $" << fixed << setprecision(2) << cost << endl;
}
return 0;
}