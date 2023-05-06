// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 2 -  Problem 11 (20 points): Put them together

#include "Customer.h"
#include "Product.h"
#include <string>
#include <iostream> 
#include <fstream>
#include <locale>
#include <iomanip>
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


int countCategory( string category, Product products[], int numProductsStored ){
    
    int count = 0;

    for (int i = 0; i < numProductsStored; i++){        //loop through products stored in array
        
        if(products[i].getCategory() == category){      //access getCategory member function for each element an see if equalt to search category
            
            count ++;                                   // increment count variable
        }

    }


    return count;
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


void printAllProducts( Product products[],int numProducts ){

    if(numProducts < 1){
        cout << "No products are stored" << endl;           //check if array has products
    }
    else{
        cout << "Here is a list of products" << endl;
        
        for(int i = 0; i< numProducts; i++){                //loop through products and print
            cout << products[i].getName() << " costs ";
            cout << products[i].getPrice() << endl;

        }

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




int addCustomer(string customerName, Customer customers[], int numProducts, int numCustomersStored, int customersArrSize){

    int emptyArr[numProducts];

    if(numCustomersStored >= customersArrSize){             //check initial condition
        return -2;
    }
    if(customerName.empty()){                                  //check if customer name is empty
        return -1;
    }

    for( int i =0; i< numCustomersStored; i++){                 //loop over customer array to see if naem already present

        if(customers[i].getCustomerName() == customerName ){
            return -1;
        }

    }

    customers[numCustomersStored+1]= Customer(customerName, emptyArr, numProducts);         //add customer to array and increase num of customers
    numCustomersStored++;
    return numCustomersStored;

}

int getCustomerStats( string customerName, Customer customers[], int numCust, int numProd){

    int index = -1;

    for (int i =0 ; i < numCust; i++){

        if(customers[i].getCustomerName() == customerName){
            index = i ;
        }
    }


    if(index == -1){
        cout << customerName << " does not exist" << endl;
        return -3;
    }


    if(customers[index].getTotalPurchaseCount() ==0){
        cout<< customers[index].getCustomerName() << " has not purchased any products" << endl;
        return 0 ;
    }

    cout << customers[index].getCustomerName() << " purchased " << customers[index].getNumUniquePurchases() << " products" << endl;
    cout << customers[index].getCustomerName() << setprecision(2)<< fixed <<  "'s average purchased quantity was " << (double) customers[index].getTotalPurchaseCount() / customers[index].getNumUniquePurchases() << endl;
    return 1;
}




int getPurchasedQuantity(string customerName, string productName, Customer customers[], Product products[], int numCust, int numProd){

int index = -3;
int numPurchases = -3;

for (int i = 0; i < numProd; i++){                      //loop through product arrray

    if(products[i].getName() == productName){           //look for index of search product and store
        index = i;
    }

}
if(index == -3){                                        //condition to check if there was a product or not
    return -3;
}

for (int x = 0; x < numCust; x++){                      //loop through customer array 

    if( customers[x].getCustomerName() == customerName){            //look for customer with name of customer were looking for
            numPurchases = customers[x].getPurchasesAt(index);      //call member function at index of product to return times purchased
    }   
}

return numPurchases;

}

int main(){

    int userOp =0;
    string filen;
    Product products[50];
    Customer customers[100];
    int numCustomersStored = 0;
    int numProductsStored = 0 ;
    int result = 0;
    string userCategory;
    string searchWord;
    string userName;




while(userOp != 9){

cout << "Select a numerical option:\n======Main Menu=====\n1. Read products from file\n2. Print all products\n3. Product-count by category\n4. Filter products by category, search word\n5. Add customer\n6. Read purchases\n7. Get purchased quantity\n8. Get customer statistics\n9. Quit" << endl;

cin >> userOp;

switch (userOp)
{


case 1:
    cout << "Enter a product file name:" <<endl;
    cin >> filen;
    result = readProducts( filen, products,numProductsStored, 50);

    if(result == -1){
        cout << "No products saved to the database." << endl;
    }
    if(result == -2){
        cout << "Database is already full. No products were added." << endl;
    }
    if( result == 50){
        cout << "Database is full. Some products may have not been added." << endl;
    }
    if(result > 0){
        numProductsStored = result;
        cout << "Total products in the database: " << numProductsStored  << endl;
    }
    break;

case 2:
    printAllProducts(products,numProductsStored);
    break;

case 3:
    cout << "Enter the category:" << endl;
    cin >> userCategory;
    result = countCategory(userCategory,products,numProductsStored);
    cout << "Total " << userCategory << " products in the database: " << result << endl;
    break;

case 4:
    cout << "Enter the category:" << endl;
    cin >> userCategory;
    cout << "Enter search word:" << endl;
    cin >> searchWord;
    result = searchNameCategory(userCategory,searchWord,products, numProductsStored);
    cout << "Number of products found for this filter:" << endl;
    cout << result << endl;
    break;

case 5:
    cout << "Enter a customer name:" << endl;
    cin >> userName;
    result = addCustomer(userName,customers,numProductsStored, numCustomersStored, 100);
    if(result == -2){
        cout << "Database is already full. Customer cannot be added." << endl;
    }
    if (result == -1){
        cout << "Customer already exists or the customerName is empty." << endl;
    }
    if( result > 0){
        numCustomersStored = result;
        cout << "Welcome, " << userName;
    }
    break;

case 6:
    cout << "Enter the purchases file name:" << endl;
    cin >> filen;
    result = readPurchases(filen,customers,numCustomersStored,100,51);
    if(result == -1){
        cout << "Nothing saved to the database." << endl;
    }
    if(result == -2){
        cout << "Database is already full. Nothing was added." << endl;
    }
    if(result == 100){
        cout << "Database is full. Some customers may have not been added." << endl;
    }
    if(result > 0){
        numCustomersStored = result;
        cout << "Total customers in the database:" << result;
    }
    break;

case 7:
    cout << "Enter a customer name:" << endl;
    cin >> userName;
    cout << "Enter a product name:" << endl;
    cin >> searchWord;
    result = getPurchasedQuantity(userName,searchWord,customers,products,numCustomersStored,numProductsStored);
    if(result == -3){
        cout << userName << " or " << searchWord << "  does not exist." << endl;
    }
    else{
        cout << userName << " has purchased " << result << " of " << searchWord;
    }
    break;

case 8:
    cout << "Enter a customer name:" << endl;
    cin >> userName;
    getCustomerStats(userName,customers,numCustomersStored,numProductsStored);
    break;

case 9:
    cout << "Good bye!" << endl;
    break;

default:
    cout << "Invalid input." << endl;
    break;
}


}

    return 0 ;

}