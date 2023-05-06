// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 

#include "Room.h"
#include <iostream>


using namespace std;

Room::Room(){                                        //default constructor
    name = "";
    player = false;
}

Room::Room(string name, Item it){                      //constructor 
    player = false;
    this->name = name;
    item = it;
}

string Room::getName(){

    return name;
}


Item Room::getItem(){

    return item;
}

void Room::setItem(string nul){

    item.setName("empty");
}

void Room::setPlayer(bool in){
    player = in;
}

bool Room::getPlayer(){
    return player;
}

void Room::setOccupant( Role role){                     //updates the occupants in the room by adding a role object to vector
    occupants.push_back(role);
}

vector <Role> Room::getOccupants(){
    return occupants;
}


string Room::getCharacterList(){                         //returns a string list of every charcter in a room
    string charList = "";

    for (int i = 0; i < occupants.size(); i++){
        charList += "\n-" + occupants[i].getName();
    }
    if(charList.size()< 3){
        return "No one.";
    }
    return charList ;                              
}