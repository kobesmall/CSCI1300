// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 5:​​bestLikenessScore()​ (8 points)


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



double bestLikenessScore(string seq1, string gold_seq){
    double best_likeness_score = 0.0;

    if(seq1.length() < gold_seq.length()){              //make sure seq1 meets initial condition
        return -1;
    }
    
    //loop over seq1
    for (int i = 0; i < seq1.length() ; i++){            
        if (calcLikenessScore(seq1.substr(i,gold_seq.length()), gold_seq)  > best_likeness_score){          //if the likenessscore of substring is greater than likeness score tracker variable
            best_likeness_score = calcLikenessScore(seq1.substr( i, gold_seq.length()), gold_seq);          //update likenessscore to likenessscore of substring
        }
    }

    return best_likeness_score;
}



int main(){

   cout << bestLikenessScore("S7H8SJ​D9H8CJD9", "H8C6D6") << endl;
    

    return 0;
}