// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 3 - Problem 2 ...


#include <iostream>
#include <iomanip>

using namespace std;


int main(){

double rev =0;
double commis = 0;

cout << "Enter the value for revenue:"<< endl;
cin >> rev;


if(rev <= 50000 && rev >= 0){
    commis = (rev * .1);
    cout << fixed << setprecision(2) << "The commission that you earn is $"  << commis << endl;
}

else if(rev >50000){
    commis = (50000 * .1) + ((rev - 50000) * .2);
      cout << fixed << "The commission that you earn is $"  << setprecision(2) << commis << endl;
}

else if(rev < 0){
    
      cout << "Invalid input." << endl;
}

return 0;
}