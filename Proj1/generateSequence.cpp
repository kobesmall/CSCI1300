// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Extra Credit Question 1: ​Creating a Random Sequence​ (3 points)

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


string generateSequence(int numOfCards){

    char suits[] = {'S','C','D','H'};                                       //array of possible suit
    char rank[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};    //array of possible ranks
    string seq;

    //loop over number of cards wanted
    for (int i = 0; i < numOfCards; i++){
        

        int rIndexS = rand() % 4;       //choose a random value between 0 and 3
        int rIndexR = rand() % 13;      // choose random value between 0 and 12
        seq = seq + suits[rIndexS] + rank[rIndexR]; //concantinate a random index from each array together to get a random card

    }

    return seq;

}



int main(){

    cout << generateSequence(3) << endl;
    cout << generateSequence(5) << endl;



}