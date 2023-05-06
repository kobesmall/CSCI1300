// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 4 - Question 5(10 points): Print reverse alphabetical triangle

#include <iostream> 
#include <string>

using namespace std;


int main(){

unsigned int height = 0;
string xyz = "zyxwvutsrqponmlkjihgfedcba"; // reverse alpha

cout << "Enter the height:" << endl;
cin >> height;

if( height > xyz.length()){                 //condition to check if height greater than xyz if so concatinate xyz with itself
    int x = height / xyz.length();
    while(x > 0){
        xyz = xyz + xyz;
        x--;
    }

}

for( int i =height; i>=1; i--){             // loop from height to 0 decrementing i to from pyramid
  
       
        cout<< xyz.substr(0,i)<< endl;      //printing substring of xyz that is of length i
        xyz = xyz + xyz.substr(0,i);        // concatinating whatever we printed to the end of xyz creating infinite string
        xyz = xyz.substr(i,xyz.length());    // cutting off what we printed so no repeats
    

}

return 0;
}