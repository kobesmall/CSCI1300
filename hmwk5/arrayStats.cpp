// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 5 - Problem 2(6 points): Array stats

#include <iostream>
#include <iomanip>
using namespace std;

void stats(double arr[], int size){
    
    double max = 0.0;
    double avg = 0.0;           //variables to rep stats
    double product = 1.0;

    //loop over the size of the array
    for (int i = 0; i<size; i++){
        if(arr[i]>max){             //check fo rmax element
            max = arr[i];
        }
        avg += arr[i];
        product *= arr[i];      //cal product through each iteraiton
        
    }
    avg = avg / size;
    cout << setprecision(3) << fixed << "Max: "<< max << endl;
    cout << setprecision(3) << fixed << "Product: " << product << endl;
    cout << setprecision(3) << fixed << "Avg: " << avg << endl;
    


}


int main(){

double test[] = {1.24, 5.68, 3.456};

stats(test,3);
}