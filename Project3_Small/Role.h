// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 






#ifndef ROLE_H
#define ROLE_H
#include "Item.h"
#include <iostream>

using namespace std;


class  Role
{
    private:
        string name;
        string room;
        Item inventory[10];
        string story;
        string alaby;
        string item;
        bool alive;

    public:
        Role();
        Role(string name ,string story, string alaby, string item);
        string getName();
        string getStory();
        string getAlaby();
        string getItem();
        void giveItem(Item item);
        string getRoom();
        string setRoom(string room);
        void move();
        

};
#endif
