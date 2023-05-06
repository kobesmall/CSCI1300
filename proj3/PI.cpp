// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#include <iostream>
#include "PI.h"


using namespace std;


PI::PI(){
    name = "";
}

PI::PI(string name){

    this->name = name;

}

string PI::getName(){

    return name;
}

string PI::getRoom(){

    return room; 
}

void PI::setRoom(string rm){
    room = rm;
}


int PI::accuse(vector <Role> roles, PI player){           //used to make final descision about who the killer is only can be used once during game
        int userIn  = 1;

        cout << "   ~Warning Detective if you accuse the wrong person or you dont have sufficeint evidence, you will lose!"  << endl;

        while (userIn != 0)
        {
            cout << "   ~Who do you want to accuse?" << endl;
            cout << "\n0. Back" << endl;
            for(int i =0; i < 6; i++){
                cout << "" << i + 1 << ". " << roles[i].getName() << endl;
                } 
            cin >> userIn;

                switch (userIn)
                {
                case 0:
                    
                    break;
                case 1:
                    return result(roles[userIn-1], player);             //calls result function based on choice to check if choice was correct
                    userIn = 0;
                    break;

                case 2:
                   return result(roles[userIn-1], player);
                   userIn = 0;
                    break;

                case 3:
                    return result(roles[userIn-1], player);
                    userIn = 0;
                    break;
                    
                case 4:
                    return result(roles[userIn-1], player);
                    userIn = 0;
                    break;

                case 5:
                     return result(roles[userIn-1], player);
                     userIn = 0;
                    break;

                case 6:
                    return result(roles[userIn-1], player);
                    userIn = 0;
                    break;

                default:
                    cout << "invalid input" << endl;
                    break;
                }
            /* code */
        }
            
    return 0;

}

void PI::move(Room ro){         //move the users player into a different room allwoing them to find more items and characters

    curRoom = ro;
    setRoom( ro.getName());

                                
                                

}


Room PI::getCurrRoom(){
    return curRoom;
}

void PI::question(vector <Role> occu){          //used to access a roles story or alaby 
    int userIn = 1;

 
    while (userIn !=0)
    {
    cout << "   ~Who do you want to question?" << endl;
    cout << "\n0. Back" << endl;
    for(int i =0; i < occu.size(); i++){
        cout << "" << i + 1 << ". " << occu[i].getName() << endl;
    } 

    cin >> userIn;
    if(userIn > occu.size()){
        cout << "invalid input" << endl;
        continue;
    }

    
    switch (userIn)
    {
    case 0:
        
        break;
    case 1:
        question(occu[userIn -1]);                  //calls question function based on user selection to gather info from role
        break;

    case 2:
        question(occu[userIn -1]);  
        break;

    case 3:
        question(occu[userIn -1]);
        break;
        
    case 4:
        question(occu[userIn -1]);
        break;

    case 5:
        question(occu[userIn -1]);
        break;

    case 6:
        question(occu[userIn -1]);
        break;

    default:
        break;
    }


    }
                  

                        

}

void PI::question(Role role){           //used in conjunction with other role  function to gather member information from role objects
    int userIn = 1;

    cout << "\n         ##Questioning: " << role.getName() << endl;

    while (userIn != 0)
    {
        cout << "\n0. Back\n1. What's your business in this house?\n2. Where were you when Master was killed?\n3. Do you have anything on you?" << endl;
        cin >> userIn;

        switch (userIn)
        {
        case 0:
            
            break;
        
        case 1:
            cout << "\n" <<  role.getName() << ":  " <<role.getStory() << endl;
            break;
        case 2:
            cout <<  "\n" <<  role.getName() << ":  " << role.getAlaby() << endl;
            break;
        case 3:
            cout <<  "\n" <<  role.getName() << ":  " <<role.getItem() << endl;
            break;

        default:
            cout << "invalid input" << endl;
            break;
        }
    }
    


}

void PI::writeDown(Item item){                          //used to store items detail in notbook to refer to later
                                    
    string note = "     ##" + item.getname()+" -  \n    " + item.getDetail() + " \n\n";
    notebook.push_back(note);
}

void PI::takeItem(Item item){                           //adds item to inventory

    inventory.push_back(item);

}

vector <Item> PI::getInventory(){
    return inventory;
}



vector <string> PI::getNotebook(){
    return notebook;
}


int PI::result(Role role, PI player){                                                       //used to decide if player is carrying the right evidence in inventory and chose the right person
cout <<role.getName() << endl;
    if(role.getName() == "Mrs. Smift"){

        for(int i= 0; i<player.inventory.size(); i++){

                 if(player.inventory[i].getname() == "Knife"){

                     for(int x = 0; x < player.inventory.size(); x++)

                            if(player.inventory[x].getname() == "Letter"){

                                for(int z = 0;  z < player.inventory.size(); z++){

                                    if (player.inventory[z].getname() =="Diary"){
                                        return 9;
                                    }
                                    
                                    

                                }

                            }
                    
                 }
            
        }
    }


    return -1;
}
