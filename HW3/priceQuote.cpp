// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 3 - Problem 6 ...


#include <iostream>

using namespace std;


int main(){

int option =0;

cout << "Enter Type of Sport: 1.Biking 2.Camping 3.Hiking 4.Rock Climbing" << endl;
cin >> option;

switch (option)
{

case 1:
    cout << "Choose type of Equipment : 1.Mountain Bike 2.Road Bike" << endl;
    cin >> option;
    switch (option)

    {
    case 1:
        cout << "Price of Mountain Bike is $500." << endl;
        /* code */
        break;
    case 2:
        cout << "Price of Road Bike is $400." << endl;
        break;
    default:
        cout << "Invalid Input." << endl;
        break;
    }
    /* code */
    break;

case 2:
    cout << "Choose type of Equipment : 1.2-Person Tent 2.4-Person Tent" << endl;
    cin >> option;
    switch (option)
    {

    case 1:
        cout << "Price of 2-Person Tent is $200." << endl;
        break;
    
    case 2:
        cout << "Price of 4-Person Tent is $300." << endl;
        break;

    default:
        cout << "Invalid Input." << endl;
        break;
    }
    break;

case 3:
    cout << "Choose type of Equipment : 1.Summer Boots 2.Winter Boots" << endl;
    cin >> option;
    switch (option)
    {
        case 1:
        cout << "Price of Summer Boots is $100." << endl;
        break;
    case 2:
        cout << "Price of Winter Boots is $150." << endl;
        break;
    default:
        cout << "Invalid Input." << endl;
        break;
    }

    break;

case 4:
    cout << "Choose type of Equipment : 1.Bouldering Pad 2.Top Rope Pad" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        cout<< "Price of Bouldering Pad is $100." << endl;
        /* code */
        break;
    case 2:
        cout << "Price of Top Rope Pad is $60." << endl;
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