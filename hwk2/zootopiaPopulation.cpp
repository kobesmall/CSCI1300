#include <iostream>

using namespace std;

int main(){
    int foxPop =11000;
    int bunPop= 23000;
    int sloPop = 19000;
    int foxGrw = 30;
    int bunGrw = -10;
    int sloGrw = 70;
    int yrs = 0;

    cout<< "Enter the number of years to estimate:"<< endl;
    cin >> yrs;

    foxPop = foxPop + (yrs * foxGrw);
    bunPop = bunPop + (yrs * bunGrw);
    sloPop = sloPop + (yrs * sloGrw);

    cout << "There will be " << foxPop << " foxes, " << bunPop<< " bunnies, and " << sloPop << " sloths in " << yrs << " years." << endl;

    return 0;
}
