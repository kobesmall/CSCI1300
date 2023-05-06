// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 1:​​reverse()​ (2 points)

#include <iostream>
#include <string>


using namespace std;




void reverse(string number){

    for (int i = number.length()-1; i >= 0; i--){      //loop over string starting at last index to first

       cout << number[i] ;                             //print out index of string

    }

cout << endl;

}





int main(){

reverse("1234567890");
reverse("04022021");

}



