#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x = 0.0;
    double ans = 0.0;

    cout<< "Enter a value for x:"<< endl;
    cin >> x;

    ans = (1/(sqrt(2 * M_PI) )   *  exp(-.5  * pow(x, 2)) );
    cout << "The probability at x=" << x << " is " << ans << endl;

    return 0;
}