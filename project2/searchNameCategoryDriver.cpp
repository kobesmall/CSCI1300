// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 5 (7 points): searchNameCategory

#include "Product.h"
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
            return numProductsStored;
        }
     }


     }

    return numProductsStored; 
}



int searchNameCategory(string category, string searchWord, Product products[], int numProductsStored){
    int count = 0 ;
    string productsFound[numProductsStored];        //array to store found products

    for (int i = 0; i< numProductsStored; i++){     //loop over product array to search through

        if( products[i].getCategory() == category){         // if product in array matches category move on

            string productName = products[i].getName();     


                for(int x =0; x < (productName.length() - searchWord.length()) +1; x++){        //loop over product name 

                    if(productName.substr(x,searchWord.length()) == searchWord){                // check if search term is in product name
                        productsFound[count] = products[i].getName();                           // if so store in found product array and increase count
                        count++;
                    }

                }

        }

    }


    if(count < 1){
        cout << "No matching products found." << endl;
    }
    if(count >= 1){
        cout << "Here is a list of products that match this category-search word pair:" << endl;
        for (int i =0; i<count; i++){
            cout << productsFound[i] << endl;
        }
    }


    return count;
}


int main(){

int totProducts = 0;
Product products[50] = {};
totProducts = readProducts("products.txt",products, 0, 50);

searchNameCategory("Home Appliances", "Toaster", products,
totProducts);

return 0;
}