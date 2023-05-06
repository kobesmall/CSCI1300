#include <iostream>

using namespace std;

int main(){
    int sec =0;
    int min =0;
    int hr =0;

    cout<< "Enter a number of seconds:"<< endl;
    cin >> sec;

    hr = sec / 3600;
    sec = sec % 3600;
    min = sec / 60;
    sec = sec % 60;

    cout << hr << " hour(s) " << min << " minute(s) " << sec << " second(s)" << endl;
}