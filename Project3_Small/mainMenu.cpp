// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 

#include "Room.h"
#include "Role.h"
#include "PI.h"
#include "Item.h"
#include "gameDriver.h"
#include <iostream>


using namespace std;


int main(){
    int userIn = 1;


/*
    Item knife = Item("Knife", "bloody");
        cout << knife.getDetail() << endl;
        cout << knife.getname() << endl;
                cout << endl;

    Role Butler = Role("Butler", "not me", "didnt do it", knife );                      // tests for creating objects
        cout << Butler.getName() << endl;
        cout << Butler.getStory() << endl;
        cout << Butler.getAlaby() << endl;
        cout << Butler.getItem() << endl;
                cout << endl;
    
    Item diary = Item( "Diary", "The butler did it!");
        cout << diary.getname() << endl;
        cout << diary.getDetail() << endl;
            cout << endl;

    Room library = Room("Library", diary);
        cout << library.getName() << endl;
        cout << library.getItem().getname() << endl;
                cout << endl;
                
    PI player = PI("Holmes");
        cout << player.getName();    */
    
    cout<<endl;
    cout<<endl;
    cout <<"   ~User lets play!\n"<<endl;
    gameDriver game = gameDriver();

    while(userIn != 0){
        cout<< "0: quit\n1: play game" << endl;                 //basic main menu to call the gameDriver or to quit
        cin >> userIn;

        switch (userIn)
        {
        case 0:
            cout << "bye" << endl;
            break;

        case 1:
            game.runGame();
            break;
            
        
        default:
            break;
        }

    }
    return 0;
}