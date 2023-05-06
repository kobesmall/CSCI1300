// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 3:​​numVowels()​ (3 points)


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

int numVowels(string sentence){
    int num_vowels = 0;

    for (int i =0; i < sentence.length(); i++){         //loop over sentence
        if(isVowel(sentence[i])){                       //returns true if letter at index i is a vowel

            num_vowels++;                           //incriments num_vowels if so
        }

    }
    return num_vowels;

}


int main(){

int numOfVowels = numVowels("CSCI 1300: Starting Computing 1");
cout << numOfVowels << endl;

numOfVowels = numVowels("​Can the lockdown end already?​");
cout << numOfVowels << endl;

}