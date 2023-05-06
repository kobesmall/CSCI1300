// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 6:​​findWinner()​ (7 points)

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




void findWinner(string seq1, string seq2, string seq3, string gold_seq){
    
    double scr1 = bestLikenessScore(seq1,  gold_seq);
    double scr2 = bestLikenessScore(seq2, gold_seq);                            //variables to track score of each player
    double scr3 = bestLikenessScore(seq3, gold_seq);


    if(scr1 == scr2 & scr2 == scr3){                                            //subsequent logic determines game result based on player score
        if(scr1 ==0){
        cout << "Better luck next time everyone!" << endl;
        }
        else{
        cout << "Congratulations everyone! You have all won!" << endl;    

        }
    }
    

    if(scr1 > scr2 ){
        if(scr1 > scr3){
            cout << "Congratulations Player 1! You have won!" << endl;
        }
        else if(scr1 == scr3){
            cout << "Congratulations Players 1 and 3! You have won!" << endl;
        }
    }
    if(scr1 > scr3 ){
        if(scr1 == scr2){
            cout << "Congratulations Players 1 and 2! You have won!" << endl;
        }
    }

    if(scr2 > scr1 ){
        if(scr2 > scr3){
            cout << "Congratulations Player 2! You have won!" << endl;
        }
        else if(scr2 == scr3){
            cout << "Congratulations Players 2 and 3! You have won!" << endl;
        }
    }
    if(scr2 > scr3 ){
        if(scr2 == scr1){
            cout << "Congratulations Players 2 and 1! You have won!" << endl;
        }
    }

    if(scr3 > scr1 ){
        if(scr3 > scr2){
            cout << "Congratulations Player 3! You have won!" << endl;
        }
    }


    
}


int main(){
    findWinner("CAH7S5CJCK","S7H9SQCA","H2S6H7CTS9HK","D4D5D6");
    findWinner("DAH7S5​CJ","S7H9DQ​CA","H2​S6CTD7","D4D5D6");
    findWinner("DAH7S5​CJ", "S7D2DQ​CAH7","H2​DTCTD7​S8C5", "DTD2D3");
    findWinner("H2​DTHTSA​S7CA", "D7H2SQ​CAH7","CJ​DAH7C5", "DTH7SA");
    
    return 0;
}