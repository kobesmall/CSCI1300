// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Homework 8 -  Question 2 (7.5 points) - Vector shuffle


#include <iostream>
#include <vector>


using namespace std;


vector <int> shuffle(vector <int> v1, vector <int> v2){

    int slength = 0;
    vector <int> svec;
    vector <int> lvec;
    vector <int> fvec;

    if (v1.size()>= v2.size()){
        for(int i = v2.size()-1; i >= 0; i--){              //checks for shorter argument vector and reverse assings it to svec
            svec.push_back(v2[i]);                           
    }
        for(int i = v1.size()-1; i >= 0; i-- ){             //longer input vector is reverse assined to lvec
            lvec.push_back(v1[i]);
        }
    }
    else {
       for(int i = v2.size()-1; i >= 0; i--){
            lvec.push_back(v2[i]);
    }
        for(int i = v1.size()-1; i >= 0; i-- ){
            svec.push_back(v1[i]);
        }
    }


    for (int i = 0; i  < svec.size() ; i++){                    //loop over shorter vector pushing values of the lvec and svec onto fvec
        fvec.push_back(lvec[i]);
        fvec.push_back(svec[i]);
    }

    for (int x = svec.size(); x < lvec.size(); x++){        //to catch whats left over of lvec and put it on the end of fvec
        fvec.push_back(lvec[x]);    
    }



return fvec;
}


int main(){

vector<int> vec1 ;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(9);

vector<int> vec2 ;
    vec2.push_back(2);
    vec2.push_back(4);
    vec2.push_back(6);
    vec2.push_back(8);
    vec2.push_back(10);

vector<int> v3 = shuffle(vec1,vec2);

for (int i=0; i < v3.size(); i++) {
    cout << v3[i] << " ";
    }

    return 0;
}