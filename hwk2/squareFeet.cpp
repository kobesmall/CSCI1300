#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double inch1 = 0;
    double inch2 = 0;
    double area = 0;
    double ft = 0;

    cout<< "Enter the length of side a in inches:"<< endl;
    cin >> inch1;
    cout<< "Enter the length of side b in inches:"<< endl;
    cin >> inch2;

    area = inch1 * inch2;
    ft = area / 144;
    cout << "The area of the rectangular field is " << fixed << setprecision(2)<< ft << " square feet" << endl;

    return 0 ;
}