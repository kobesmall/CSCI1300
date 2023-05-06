#include <iostream>

using namespace std; 
int main()
{

	int month; 
	cout << "Enter a month:" << endl; 
	cin >> month; 
    
	if(month >= 3 && month <= 5){
		cout << "It's spring, the weather is sunny and pleasant." << endl;

    }
	else if(month >= 6 && month <= 8){
		cout << "It's summer, time for ice-cream." << endl; 
	}
    else if (month >= 9 && month <= 12){
        cout << "It's autumn, the holidays are near." << endl; 
	} 
    else if(month >=1 && month <=2){
		cout << "It's winter, time to wrap up warm." << endl; 
	}
    else {
		cout << "Invalid" << endl; 
	}

	return 0;

}