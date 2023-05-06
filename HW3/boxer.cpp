// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 3 - Problem 4 ...


#include <iostream>

using namespace std;


int main(){

int wt1 =0;
int wt2 =0;
int wt3 =0;

cout << "Enter boxers' weights"<< endl;
cin >> wt1;
cin >> wt2;
cin >> wt3;


if(wt1 > wt2 && wt2 > wt3){
    cout << "Descending order" << endl;
}
else if (wt3 > wt2 && wt2 > wt1){
    cout << "Ascending order" <<endl;
}
else{
    cout << "Neither" << endl;
}
return 0;
}