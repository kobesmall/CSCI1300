#include <iostream>


using namespace std;


int main(){

    int in1 = 0;
    int in2 = 0;
    int in3 = 0;

    cout << "Enter the first value for an item:" << endl;
    cin >> in1;
    cout << "Enter the first value for an item:" << endl;
    cin >> in2;
    cout << "Enter the first value for an item:" << endl;
    cin >> in3;

    if (in1 > in2 && in1 > in3){
        cout << "The most expensive item has a price of " << in1 << endl;
    }
    else if (in2 > in1 && in2 > in3){
        cout << "The most expensive item has a price of " << in2 << endl;
    }
    else if (in3 > in1 && in3 > in2){
        cout << "The most expensive item has a price of " << in3 << endl;
    }
    else {
        if(in1 > in2 && in1 == in3 ){
             cout << "The most expensive item has a price of " << in1 << endl;
        }
        else if(in2 > in1 && in2 == in3){
        cout << "The most expensive item has a price of " << in2 << endl;
        }
        else if(in1 > in3 && in1 == in2 ){
             cout << "The most expensive item has a price of " << in1 << endl;
        }
        else {
             cout << "The most expensive item has a price of " << in1 << endl;
        }
        
    }
    return 0;

}