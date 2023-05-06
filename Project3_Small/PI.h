// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#ifndef PI_H
#define PI_H
#include "Item.h"
#include "Room.h"
#include <iostream>
#include <vector>

using namespace std;


class PI
{
    private:
        string name;
        vector <Item> inventory;
        vector <string> notebook;
        string room;
        Room curRoom = Room();


    public:
        PI();
        PI(string name);
        void examine();
        int accuse(vector <Role> roles, PI player);
        void move(Room room);
        void question(vector <Role> occu);
        void question(Role ro);
        void writeDown(Item item);
        void takeItem(Item item);
        void checkTime();
        string getName();
        string getRoom();
        Room getCurrRoom();
        void setRoom(string room);
        vector <string>  getNotebook();
        vector <Item> getInventory();
        int result(Role role, PI player);




};


#endif