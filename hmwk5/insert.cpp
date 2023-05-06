// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 5 - Problem 3(7 points): Insert into a String

#include <iostream>
#include <iomanip>
using namespace std;



int insert(char arr[], int cha, int size, int voul){
char vowels[] = {'a','e','i','o','u'};  //char array of possible vowels to search parameter through
string res;
int count=0;
int y =0;


for (int i =0; i<cha; i++) {
    for (int j =0 ; j <5; j++){
        if(vowels[j]==arr[i]){
            res += arr[i];
            y++;
            count++;
        }
        
    }
    res += arr[i];
    y++;
    count++;
}



//arr = res;

if(count <= size){
for (int i = 0; i < size; i++){
arr[i] = res[i];
}
}



return count;
}


int main(){

char test[] = {'c','a','t',' ',' '};
cout << insert(test,3,5,1) << endl;
cout << "String after insertion:\n" << test << endl;

char tet2[] = {'n','o','u','v','e','a','u',' '};

cout << insert(tet2,7,8,5) << endl;

cout << tet2 << endl;

}