// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 2:​​isVowel()​ (2 points)


#include <iostream>
#include <string>


using namespace std;


bool isVowel(char letter){

    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};  //char array of possible vowels to search parameter through
    int i;

        for (i = 0; i < 10; i++) {          //loop over vowel array 
            if (vowels[i]==letter){         //condition checks if letter is in array
                return true;
            }

        }

    return false;

}


int main(){

bool vowelCheck = isVowel('I');
cout << vowelCheck << endl;

vowelCheck = isVowel('k');
cout << vowelCheck << endl;

}