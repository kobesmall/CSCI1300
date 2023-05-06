// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 3 - Problem 5 ...


#include <iostream>

using namespace std;


int main(){

int option =0;

cout << "Enter Type of Phone : 1.iPhone 2.Android" << endl;
cin >> option;

    switch (option)
    {
        
    case 1:
        cout << "Enter Year Made : 1.Before 2015 2.After 2015"<< endl;
        cin >> option;
        switch (option)


        {
        case 1:

            cout << "Enter Storage Capacity : 1.32GB 2.64GB"<< endl;
            cin >> option;
            switch (option)


            {
            case 1:
               cout << "Price of the phone is $100." << endl;
                break;
            case 2: 
                cout << "Price of the phone is $150." << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
                break;
            }
            break;
        
        case 2:
        cout << "Enter Storage Capacity : 1.64GB 2.128GB 3.256GB"<< endl;
            cin >> option;
            switch (option)

            {
            case 1:
               cout << "Price of the phone is $175." << endl;
                break;
            case 2: 
                cout << "Price of the phone is $200." << endl;
                break;
            case 3:
                cout << "Price of the phone is $250." << endl;
                break;
            default:
            cout << "Invalid Input." << endl;
                break;
            }
            break; 
        

        default:
            cout << "Invalid Input." << endl;
            break;
        }
        break;
    

    case 2:
    cout << "Enter Year Made : 1.Before 2015 2.After 2015"<< endl;
        cin >> option;
        switch (option)


        {
        case 1:

            cout << "Enter Storage Capacity : 1.32GB 2.64GB"<< endl;
            cin >> option;
            switch (option)


            {

            case 1: 
                cout << "Price of the phone is $75." << endl;
                break;
            case 2:
                cout << "Price of the phone is $100." << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
                break;
            }
            break;
        
        case 2:
        cout << "Enter Storage Capacity : 1.64GB 2.128GB 3.256GB"<< endl;
            cin >> option;
            switch (option)

            {
            case 1:
               cout << "Price of the phone is $150." << endl;
                break;
            case 2: 
                cout << "Price of the phone is $170." << endl;
                break;
            case 3:
                cout << "Price of the phone is $200." << endl;
                break;
            default:
            cout << "Invalid Input." << endl;
                break;
            }
            break;

        default:
            cout << "Invalid Input." << endl;
            break;
        }
        break;

    default:

         cout << "Invalid Input." << endl;
        break;
    }
return 0;
}