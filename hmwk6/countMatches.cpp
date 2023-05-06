// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 4 - Question 4(10 points): Count matches


#include <iostream> 
#include <string>

using namespace std;


int main(){


string usrStr1;
string usrStr2;
int count = 0;

cout << "Enter the search string:"  << endl; //ask user for input
cin >> usrStr1;
cout << "Enter the substring to be searched:" << endl;
cin >> usrStr2;

for (int i =0; i <= (usrStr1.length() - usrStr2.length()); i++){      //loop through user string
    if( usrStr1.substr(i,usrStr2.length()) == usrStr2){              // checks if user substring equals the substring from i to usrStr2
        count++;                                                     //if match found increment count
    }
}
cout << "Number of occurrences: " << count << endl;
return 0;

}
