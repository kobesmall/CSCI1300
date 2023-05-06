#include <iostream>

using namespace std;

int main(){
    int tsp =0;
    int tbsp =0;
    int cups =0;

    cout<< "Enter the number of teaspoons:"<< endl;
    cin >> tsp;

    cups = tsp / 48;
    tsp = tsp % 48;
    tbsp = tsp / 3;
    tsp = tsp % 3;

    cout << cups << " cup(s) " << tbsp << " tablespoon(s) " << tsp << " teaspoon(s)" << endl;
}