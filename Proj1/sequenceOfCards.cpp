// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 1 - Question 7:​ Putting it all Together using​ main()​ (5 points)

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

    int userOp = 0;
    string seq1;
    string seq2;
    string seq3;
    string gold_seq;
    

    //while loop keeps menu on
    while(userOp != 4){
            cout << "----Menu!----\n"
    "Choice 1: Calculate the Likeness Score between 2 strings of equal length.\n"
    "Choice 2: Calculate the Best Likeness Score between 2 sequences of possibly different length.\n"
    "Choice 3: Find winner among sequences of 3 players and a Golden Sequence.\n"
    "Choice 4: Exit.\n"
    "Enter your choice (1-4):" << endl;

        cin >> userOp;
        switch (userOp)

        //different cases based on menu and user input
        {
        case 1:
            cout << "Enter Sequence 1" << endl;
            cin >> seq1;
            cout << "Enter Sequence 2" << endl;
            cin >> seq2;
            if(calcLikenessScore(seq1,seq2) == -1){
                cout << "Invalid input. Sequences of different length." << endl;
            }
            else{
                cout << "Score: " << calcLikenessScore(seq1,seq2) << endl;
            }
            break;
        case 2:
            cout << "Enter Sequence 1" << endl;
            cin >> seq1;
            cout << "Enter Sequence 2" << endl;
            cin >> seq2;
            cout << "Best Likeness Score: " << bestLikenessScore(seq1,seq2) << endl;
            break;
        case 3:
            cout << "Enter Sequence of Player 1" << endl;
            cin >> seq1;
            cout << "Enter Sequence of Player 2" << endl;
            cin >> seq2;
            cout << "Enter Sequence of Player 3" << endl;
            cin >> seq3;
            cout << "Enter Golden sequence" << endl;
            cin >> gold_seq;
            findWinner(seq1,seq2,seq3,gold_seq);
            break;
        case 4:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid Input. Choices between 1-4." << endl;
            break;
        }

    }
    
    return 0;
}