// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 4 - Question 1(5 points): Sum odd positive numbers


#include <iostream> 

using namespace std;


int main(){

int usrNum = 0;
int tot = 0;            // total of odd

cout << "Enter a positive number:"  << endl; //ask user for input
cin >> usrNum;


if (usrNum < 0){
 cout << "Invalid input." << endl;      // check input
 return 0;
}


for  (int i = 0 ; i<= usrNum; i++){     // loop over usrNum
    if ( !(i % 2 == 0)){                // check if i is odd
            tot = tot + i;              //if i odd add to tot
    }

}

cout<< "Sum: " << tot << endl;

return 0;

}
