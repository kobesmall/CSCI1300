// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 8 -  Question 4 (7.5 points): decimalToBinaryRecursive


#include <iostream> 
#include <vector>



using namespace std;

string decimalToBinaryRecursive(int n)
{
    if(n == 0){                                     //base case
        return "0";
    }
    else {
       return decimalToBinaryRecursive(n/2) + to_string(n % 2);         //recursive call and concatinatinf remainder as string

    }
}

int main(){
    string ans;

    ans = decimalToBinaryRecursive(6);
    cout << ans << endl;
    ans = decimalToBinaryRecursive(5);
    cout << ans << endl;
    ans = decimalToBinaryRecursive(8);
    cout << ans << endl;
return 0;
}