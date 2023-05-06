// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include <iostream>
#include "Room.h"
#include "Role.h"
#include "PI.h"
#include "Item.h"
#include "vector"


using namespace std;

class gameDriver
{
    private:
        vector <Room> rooms;
        vector <Item> items;
        vector <Role> roles;
        string name;

    public:
        gameDriver();
        int split(string seq, char del, string arr[], int size);
        void popRooms(string filename);
        void popItems(string filename);
        void popRoles(string filename);
        void runGame();
        void setRoom(Room ro );
        Room getRoom(int index);
        PI changeRoom(PI player);
        PI searchRoom(Room room, PI player);
        void gameResult(int num);



};

#endif