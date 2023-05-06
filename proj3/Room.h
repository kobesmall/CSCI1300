// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "Role.h"
#include "Item.h"
#include <vector>


using namespace std;


class Room
{
    private:
        bool player;
        string name;
        Item item;
        vector <Role> occupants;
    
    public:
        Room();
        Room(string name, Item item);
        string getName();
        Item   getItem();
        void setItem(string nul);
        string getCharacterList();
        void setPlayer(bool in);
        bool getPlayer();
        void setOccupant(Role role);
        vector <Role> getOccupants();



};


#endif