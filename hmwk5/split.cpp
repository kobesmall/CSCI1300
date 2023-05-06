// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 5 - Problem 5(13 points): split a string

#include <iostream>
#include <iomanip>
using namespace std;

int split(string seq, char del, string arr[], int size){

int splits = 0;
unsigned int x;

if(seq.length()==0){
    return 0;
}

else{
    for (int i = 0; i < size; i++){
        for(x =0; x < seq.length(); x++){
        if( splits > size ){
            return -1;
        }
        if(seq[x] == del ) {
            arr[splits] = (seq.substr(0,x));
            seq = seq.substr(x+1,(seq.length()-(x)));
            splits++;
        }
        
        }
 
    }
    arr[splits]=seq;
    splits++;
    return splits;
}

}


int main (){
    string test = "Apples,Bannas,Oranges";
    string arr[3];

    split(test,'-',arr,3);
    cout << arr[0] << endl;
    cout << arr[1] << endl;
     cout << arr[2] << endl;

    return 0;
}