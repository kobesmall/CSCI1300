// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 7 (15 points): readPurchases

#include "Customer.h"
#include <iostream> 
#include <fstream>
#include <iostream>

using namespace std;




int split(string seq, char del, string arr[], int size){        //splt function

int splits = 0;
unsigned int x;


if(seq.length()==0){
    return 0;
}

else{
    for (int i = 0; i < size; i++){
        for(x = 0; x < seq.length()-1; x++){
      
             if(seq[x] == del ) {
            
                 if( splits >= size - 1 ){
                    arr[splits] = (seq.substr(0,x));
                    return -1;  
                    }
                        arr[splits] = (seq.substr(0,x));
                        //cout << arr[splits] << endl;
                        seq = seq.substr(x+1,(seq.length()-x+2));
                        //cout<< seq<< endl;
                        splits++;
                        break;
                    }
        
        }
    }
    arr[splits]=seq;
    //cout << arr[splits] << endl;
    splits++;
    return splits;
  }
}



int readPurchases(string filename, Customer customers[],int numCustomersStored, int custArrSize, int maxCol){

ifstream in1;
in1.open(filename);
string line;
string linesplit[maxCol];
int purchases[maxCol-1];



if(numCustomersStored >= custArrSize){    // puts the return precidence higher than -1 (file fail)
            return -2;
        }

if (in1.fail()){                              //checks if file is in a failed state for intitial condition
        
     
      return -1;
}

while (getline(in1, line)) {                //while lines in file

     if(!line.empty()){                       //if the line isnt empty
         split(line, ',',linesplit,maxCol);              //store contents of line in array deliminated by ,
        
        string name = linesplit[0];
        //cout << linesplit[50] << endl;

        customers[numCustomersStored] = Customer();
        customers[numCustomersStored].setCustomerName(name);
        for (int i = 1 ; i < maxCol; i ++){         //loop over the linesplit array after the name to store purchases
        //cout << linesplit[i];
        customers[numCustomersStored].setPurchasesAt(i-1,stoi(linesplit[i]));
        //purchases[i-1] = stoi(linesplit[i]);
        //cout << purchases[i-1] ;
        }

        //customers[numCustomersStored] = Customer(name,purchases,custArrSize);
        numCustomersStored++;                                                     //increase total number of customers in array
        if(numCustomersStored == custArrSize){                                   //check array size condition
            return numCustomersStored;
        }
     }


     }

    return numCustomersStored; 
}






int main(){

const int custArrSize = 10;
Customer customers[custArrSize];
int numCustomersStored = 0;
cout << readPurchases("purchases.txt", customers,numCustomersStored, custArrSize, 50) << endl; 
cout<<customers[0].getCustomerName()<<endl;
cout<<customers[1].getCustomerName()<<endl;
cout<<customers[2].getCustomerName()<<endl;
cout<<customers[3].getCustomerName()<<endl;


cout<<customers[0].getPurchasesAt(0)<<endl;
cout<<customers[0].getPurchasesAt(1)<<endl;
cout<<customers[0].getPurchasesAt(2)<<endl;
cout<<customers[0].getPurchasesAt(3)<<endl;
cout<<customers[0].getPurchasesAt(4)<<endl;
return 0;
}