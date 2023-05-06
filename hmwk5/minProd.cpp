// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 5 - Problem 4(10 points):  product of the min value found in each row

#include <iostream>
#include <iomanip>
using namespace std;


int minProd( int arr[][10], int rows){

    int prod = 1;
    int minr = 0;       //variables to rep the min in each row and the product of those mins
    


    for(int i = 0; i < rows; i++){          //loop over rows
        minr = arr[i][0];                   //set min value to first element in each row

        for(int j = 0; j < 10; j++){        //loop over cols
            if( arr[i][j]< minr){           //check for min vlaue
                minr = arr[i][j];
            }
        }
        
        prod *= minr;                       //calc product

    }


    return prod;

}

int main(){

    return 0;
}