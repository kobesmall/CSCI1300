// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 5 - Problem 1(4 points): array pilgrimage

#include <iostream>

using namespace std;


int main(){

    double distance[10];
    string cars[] = {"Tesla","Hyundai","Mercede​s","Ford","Ferrari"};  //easier just to initialize
    int sequence[100];
    char letters[52];

    //loop over the 10 indecies
    for (int i =0; i<10; i++){
        distance[i]=324.5;
        cout << distance[i] << endl;
    }

    cout << endl;


    for (int i = 0; i <=4;i++ ){
        cout << cars[i] << endl;
    }

    cout << endl;

    //two variables to represent the indecies of array(y) and the place of the next positive even int
    int y = 0;
    int i =2;
    while( i <= 200){
        if(i % 2 ==0){              //check if int is even
            sequence[y]=i;
            cout << sequence[y] << endl;
            i+=2;                           //increment int by 2 so it stays even
            y+=1;                              //increment y to next index
        }
        else{
            i++;
        }
    }

    cout << endl;

    int z =0;   
    for (int x= 65; x<=90; x++){        //loop over the length of the alphabet 
        letters[z]= (char)x;            //x represents "index" of assci table
        letters[z+1]= (char)(x+32);     //x+32 get the lowercase equivalent to the previous letter
        cout<< letters[z]<<" " << letters[z+1]<<endl;
        z += 2;                         //increment index variable by 2 as were adding two elements to array every iteraiton
    }

}