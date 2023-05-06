// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 4 - Question 3(8 points): Recipe index


#include <iostream> 

using namespace std;


int main(){

int flour = 0;
int eggs = 0;
int sugar = 0;
int cream = 0;
int cocoa = 0;
int vanilla = 0;

int usrIn = 0;

while ( usrIn != 4){                   // will keep program "live" while user input isnt 4
 cout << "Select a numerical option:\n=== menu ===\n1. Vanilla cake\n2. Chocolate cake\n3. Pound cake\n4. Quit"<< endl;
  cin >> usrIn;

  switch (usrIn)

  {
    case 1:                                                                   //switch for menu options
      cout << "How many grams of flour do you have?"<< endl;
      cin >> flour;
      cout << "How many grams of sugar do you have?" << endl;
      cin >> sugar;
      cout << "How many eggs do you have?" << endl;
      cin >> eggs;
      cout << "How many grams of vanilla extract do you have?" << endl;
      cin >> vanilla;
      if ( flour >= 440 && sugar >= 400 && eggs >= 3 && vanilla >= 15){         //conditions to see if they can make cake
          cout << "You can make a vanilla cake." << endl;
      }
      else{
          cout << "You don't have enough for a vanilla cake." << endl;
      }
      break;

    case 2:                                                                   //switch for menu 2
      cout << "How many grams of flour do you have?"<< endl;
      cin >> flour;
      cout << "How many grams of sugar do you have?" << endl;
      cin >> sugar;
      cout << "How many eggs do you have?" << endl;
      cin >> eggs;
      cout << "How many grams of cocoa powder do you have?" << endl;
      cin >> cocoa;
      if ( flour >= 440 && sugar >= 400 && eggs >= 3 && cocoa >= 120){         //conditions to see if they can make cake
          cout << "You can make a chocolate cake." << endl;
      }
      else{
          cout << "You don't have enough for a chocolate cake." << endl;
      }
      break;

    case 3:                                                                   //switch for menu 3
      cout << "How many grams of flour do you have?"<< endl;
      cin >> flour;
      cout << "How many grams of sugar do you have?" << endl;
      cin >> sugar;
      cout << "How many eggs do you have?" << endl;
      cin >> eggs;
      cout << "How many grams of cream cheese do you have?" << endl;
      cin >> cream;
      if ( flour >= 440 && sugar >= 400 && eggs >= 3 && cream >= 220){         //conditions to see if they can make cake
          cout << "You can make a pound cake." << endl;
      }
      else{
          cout << "You don't have enough for a pound cake." << endl;
      }
      break;

    case 4:
        cout << "Goodbye!"<< endl;
        break;
  
     default:
     cout << "Invalid input." << endl;
      break;
  }

}

return 0;
}