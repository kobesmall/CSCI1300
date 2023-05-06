// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 4 - Question 2(7 points): Print mathematical sequence


#include <iostream> 

using namespace std;


int main(){


int usrNum = 0;

cout << "Enter a positive number:"  << endl; //ask user for input
cin >> usrNum;


if (usrNum <= 0){
 cout << "Invalid input." << endl;      // check input
 return 0;
}

cout << usrNum << endl;         //initial print

while( usrNum > 1){            // update usrNum until it usrNum greater than or equal to 1

    if( usrNum % 3 == 0){       //check is usrNum is multiple of 3
        usrNum = usrNum -1;
        cout << usrNum << endl;
    }

    else {
         usrNum = usrNum /2;     // else conditon
         cout << usrNum << endl;
     }
}



return 0;
}