// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 7 - Problem 6 (14 points): put them together


#include "Product.h"
#include <iostream> 
#include <fstream>
#include <iostream>

using namespace std;



void printAllProducts( Product products[],int numProducts ){

    if(numProducts < 1){
        cout << "No products are stored" << endl;           //check if array has products
    }
    else{
        cout << "Here is a list of products" << endl;
        
        for(int i = 0; i< numProducts; i++){                //loop through products and print
            cout << products[i].getName() << " costs ";
            cout << fixed << setprecision(2) << products[i].getPrice() << endl;

        }

    }

}


int split(string seq, char del, string arr[], int size){        //split function

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
                        seq = seq.substr(x+1,(seq.length()-x+2));
                        splits++;
                        break;
                    }
        
        }
    }
    arr[splits]=seq;
    splits++;
    return splits;
  }
}



int readProducts(string filename, Product products[],int numProductsStored, int productArrSize){

ifstream in1;
in1.open(filename);
string line;
string linesplit[4];

if(numProductsStored == productArrSize){    // puts the return precidence higher than -1 (file fail)
            return -2;
        }

if (in1.fail()){                              //checks if file is in a failed state for intitial condition
        
     
      return -1;
}

while (getline(in1, line)) {                //while lines in file

     if(!line.empty()){                       //if the line isnt empty
         split(line, ',',linesplit,4);              //store contents of line in array deliminated by ,
        string name = linesplit[0];
        double price = stod(linesplit[1]);
        string catergory = linesplit[2] ;
        products[numProductsStored]  = Product(name,price,catergory);   //make product object based on split array with appropriate indicies alinging with memeber variables and store in products array


        numProductsStored++;                                //increase total number of products in array
        if(numProductsStored == productArrSize){            //check array size condition
            cout << "Database is full. Some products may have not been added."<< endl;
            return numProductsStored;
        }
     }


     }

    return numProductsStored; 
}



int main(){

string filen;
Product products[50] = {};
int totProducts = 0;
int returnP = 0;
int userIn = 0;


while(userIn != 3){                                             //live menu formating

cout << "======Main Menu=====\n1. Read products\n2. Print all products\n3. Quit" << endl;       //menu
cin >> userIn;

    switch (userIn)                                             //swicth statement for user input
    {
    case 1:
        cout << "Enter a product file name:"<<endl;
        cin >> filen;

        returnP = readProducts(filen,products,totProducts,50);
        if(returnP   == -1){              //if the return of the fuction call indicates a unsuccessfull read/store
            cout << "No products saved to the database." << endl;
        }
        else if(returnP   == -2){
            cout << "Database is already full. No products were added." << endl;
        }
        else{
            totProducts = returnP;
            cout << "Total products in the database: " << totProducts << endl;
        }

        break;

    case 2:
        printAllProducts(products,totProducts);                         //call to print all products stored in product array
        break;
    
    case 3:
        cout<<"Good bye!" << endl;
        break;
    
    default:
        cout << "Invalid input." << endl;
        break;
    }

}

return 0;
}