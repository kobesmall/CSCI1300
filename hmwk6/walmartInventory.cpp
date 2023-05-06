// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 6 - Question 1 (10points): Walmart Inventory

#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//split fuction from previous hw
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



int fila(string fileN){

    ifstream in1;

    in1.open(fileN);
    string line;
    int numlines = 0;
    int maxPrice = 0;
    string maxProd;
    int minPrice = 999999999;                 
    string minProd;
    string lineSplit[3];
    char del = ',';
    int size = 3;


    if (in1.fail()){                              //checks if file is in a failed state for intitial condition
        
        cout << "Could not open file." << endl;
              return -1;
    }

    while (getline(in1, line)) {                      //while there are lines in the file
         if(!line.empty()){                           //while the line is not empty
           numlines++;                                //counting number of lines
           split(line, del, lineSplit, size);          //call to split
                
                if(stod(lineSplit[1].substr(1,6))  >  maxPrice ){     //condition to find the first item with max value
                  maxPrice = stod(lineSplit[1].substr(1,6));
                  maxProd = lineSplit[0];
                }

                

                if(stod(lineSplit[1].substr(1,6))  <  minPrice){      // condition to find first item with min value
                  minPrice = stod(lineSplit[1].substr(1,6));
                  minProd = lineSplit[0];
                }
           
         }

    }

    cout << "The number of lines: " << numlines << endl;
    cout << "The most expensive product: " << maxProd << endl;
    cout << "The least expensive product: " << minProd << endl;

    in1.close();
    return -1;
}





int main(){

string userIn;

cout << "Enter the file name:" << endl;
cin >> userIn ;

fila(userIn);


return 0;
}