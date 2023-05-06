// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 




#include <iostream>
#include "Role.h"



using namespace std;

Role::Role(){
    name = "";
    story = "";
    alaby = "";
}

Role::Role(string nm, string st, string al, string it){
    name = nm;
    story = st;
    alaby = al;
    item =it;
}

string Role::getName(){
    return name;
}

string Role::getAlaby(){
  return alaby;
}


string Role::getStory(){
    return story;
}

string Role::getItem(){
    return item;
}

string Role::getRoom(){

    return room;
}

void Role::move(){
                                //will move character to a different room *randomly by changing room string 
                                //and updating that rooms characters the person is in
}