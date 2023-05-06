// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 8 -  Question 3 (7.5 points): decimalToBinaryIterative



#include <iostream> 
#include <vector>



using namespace std;

string decimalToBinaryIterative(int n)
{
    if(n==0){
        return "0";
    }
    string ans;
    string binary;
       
    while (n > 0) {

        
        binary += to_string(n % 2);         // storing remainder of 2 in binary string
        n = n / 2;                             //divide by 2
     
    }

    for (int i = binary.length() - 1; i >= 0; i--){         //reversing binary string
        ans +=  binary[i];
    }

    return ans;
}

int main(){
    string ans;

    ans = decimalToBinaryIterative(6);
    cout << ans << endl;
    ans = decimalToBinaryIterative(5);
    cout << ans << endl;
    ans = decimalToBinaryIterative(8);
    cout << ans << endl;
return 0;
}