// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 6 - Question 2 (13 points): Work Hours

#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Put only the functions. 
// If you put int main(){ ... }, it will say an error: redefinition of ‘int main()’
int split(string seq, char del, string arr[], int size){        //splt function

int splits = 0;
unsigned int x;


if(seq.length()==0){
    return 0;
}

else{
    for (int i = 0; i < size; i++){
        for(x = 0; x < seq.length()-1; x++){
      

        if(seq[x] == del ) {
            
            if( splits >= size - 1 ){
            arr[splits] = (seq.substr(0,x));
            return -1;
            
        }

            arr[splits] = (seq.substr(0,x));
            //cout << arr[splits] << endl;
            seq = seq.substr(x+1,(seq.length()-x+2));
            //cout<< seq<< endl;
            splits++;
            break;
        }
        

        
        }
 
    }

    arr[splits]=seq;
    //cout << arr[splits] << endl;
    splits++;
    return splits;
}

}



int workHours(string fileN, string emps[], int workHrs[][12], int size){

int numemps = 0;
ifstream in1;
in1.open(fileN);
string line;
string lineSplit[13];
double avg = 0.0;


if (in1.fail()){                              //checks if file is in a failed state for intitial condition
        
     
      return -1;
}

int i =0;
while (getline(in1, line)) {                      //while there are lines in the file
if (i > size-1){
    break;
}
    
    if(!line.empty()){ 
        emps[i] = line;                         //sets first and subsequent top line containinf employee name in emplyee array
        
        cout<< emps[i] << ": " ;    

        getline(in1,line);                          //gets next line
        avg = 0.0;
        
        split(line, ',', lineSplit, 13);            
        for (int x = 0; x < 12; x++){       //splits hours worked by ',' and stores in array
           workHrs[numemps][x] = stoi(lineSplit[x]);            //stores hours in 2d array based on which employee

            avg += stod(lineSplit[x]);                  //adds the hours togther

        }
        avg = avg /12;
        cout << setprecision(1) << fixed << avg << endl;
        numemps++;
    }
    i++;
}



return numemps;

}



int main(){

string fileN = "hours.txt";
string emps[10];
int workhrs[10][12];
int size = 10;


workHours(fileN, emps, workhrs, size);


return -1;
}