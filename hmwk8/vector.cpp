// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 8 -  Question 1 (7.5 points): Introduction to vectors



#include <iostream> 
#include <vector>



using namespace std;



int main(){



int min = 99999999;                 //min variable set at massinve number
int max = 0;
string usr;
int userIn = 0;
vector<int> vec;                    //vector declaration


 
while ( userIn != -1){              //while loop for user unput
    cout << "Please enter a number:" << endl;


if (!(cin >> userIn))
{
    cin.clear();                                                                        // stop terminal from infinite loop if user enters char
    cout << "The number should be a positive integer or -1." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');                                // 
}

else{



    if(userIn == 0 || userIn < -1){                                                 //userInput condition
        cout << "The number should be a positive integer or -1." << endl;
    }

    if(userIn == -1){                                                          //exit condition
        break;
    }

    if( !(userIn == 0 || userIn < -1) ){ 
                if(vec.size() == 0){
                    vec.push_back(userIn);
                    continue;
                }
                if(userIn % 5 == 0){
                    vec.erase(vec.begin());                                 //specified conditions and their actions as described in directions
                }
                if(userIn % 3 == 0){
                    vec.pop_back();
                }

                if( !(userIn % 5 == 0) && !(userIn % 3 == 0) ){
                    vec.push_back(userIn);                               
                }
    }
    

}

if( vec.size() < 1 ){                                            //check if vector is empty
    cout << "The vector is empty." << endl;
    return 0;
}

else{
    cout << "The elements in the vector are:";

        
        for(int i = 0; i< vec.size(); i++){         //loop through vector and print elements
            cout << " " << vec[i];

                    if(vec[i] > max){

                         max = vec[i];          //find max and min
                     }

                    if(vec[i] < min){
                        min = vec[i];
                    }
        }
    cout << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
}
return 0;
}