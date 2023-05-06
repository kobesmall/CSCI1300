// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 4:​​calcLikenessScore()​ (8 points)


#include <iostream>
#include <string>


using namespace std;

double calcLikenessScore(string seq1, string seq2){
    double likeness_score = 0.0;
    double sSuit = 0.0;                             //same suit counter
    double suitRank = 0.0;                          //same suit and rank counter

    if( seq1.length() != seq2.length()){            //condition to make sure input is valid
        return -1;
    }

    for( int i = 0; i< seq1.length(); i++){         //loop over sequence length
        if( i % 2 == 0  && seq1[i]==seq2[i]){       //checks if index is even i.e. a suit if its a suit and equal in both seq

            if(seq1[i+1] == seq2[i+1]){             // checks if its the same rank within it the same suit
                suitRank++;     

            }
            sSuit++;

        }

    }
    likeness_score = (sSuit / (seq1.length() / 2)) + ( 1 * suitRank);          // likeness_score equation, sequene always has double elements than cards

    return likeness_score;
}



int main(){

    cout << calcLikenessScore("S7H8CJD9HA", "S7H8CJD9HA") << endl;
    cout << calcLikenessScore("HQDASJ", "DAD8SJ") << endl;

    return 0;
}