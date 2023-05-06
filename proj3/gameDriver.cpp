// CS1300 Spring 2021
// Author: Kobe Small
// Recitation: 122 – Sourav Chakraborty
// Project 3 


#include "gameDriver.h"
#include "Room.h"
#include "Role.h"
#include "PI.h"
#include "Item.h"
#include <iostream>
#include <fstream> 
#include <ostream>
#include <stdlib.h>


using namespace std;


int gameDriver::split(string seq, char del, string arr[], int size){        //split function

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

void gameDriver::setRoom(Room ro){
    rooms.push_back(ro);
}

Room gameDriver::getRoom(int index){
    return rooms[index];
}


void gameDriver::popRooms(string filename){                     //used to populate room vector with info from a file ie creates house/gameboard
ifstream in1;
in1.open(filename);
string line;
string linesplit[2];
int i =0;

while (getline(in1, line)) {                //while lines in file

    if(!line.empty()){                       //if the line isnt empty
        split(line, ',',linesplit,2);              //store contents of line in array deliminated by ,

        //cout << linesplit[0]<< endl;
        //cout << items[i].getname() << endl;
        rooms.push_back( Room(linesplit[0],items[i]));
        i++;
    }
}
in1.close();
}



void gameDriver::popItems(string filename){                     //populates item vector with info from a file items that will be found in each room
ifstream in1;
in1.open(filename);
string line;
string linesplit[2];
string test;
int i =0;

while (getline(in1, line)) {                //while lines in file

    if(!line.empty()){                       //if the line isnt empty
        split(line, ',',linesplit,2);              //store contents of line in array deliminated by ,

        items.push_back ( Item(linesplit[0],linesplit[1]));
        
        i++;
    }
}   
}


void gameDriver::popRoles(string filename){                             //populates roles vector these will be the people in the house
ifstream in1;
in1.open(filename);
string line;
string linesplit[4];
string test;
int i =0;

while (getline(in1, line)) {                //while lines in file

    if(!line.empty()){                       //if the line isnt empty
        split(line, ',',linesplit,4);              //store contents of line in array deliminated by ,

        roles.push_back( Role(linesplit[0],linesplit[1],linesplit[2],linesplit[3]));
        
        i++;
    }
}   
}



PI gameDriver::changeRoom(PI player){                                                       //moves the player throughout the house

    int userIn = 1;

    for (int i = 0; i < rooms.size(); i++){
        

        if((rooms[i].getName() == player.getRoom())  || (rooms[i].getPlayer())){             //finds what room player is in and removes him from it
        cout <<"leaving: \n" <<rooms[i].getName() <<player.getRoom() << endl;
            rooms[i].setPlayer(false);
        }   


    }

    while (userIn != 0)
    {
        cout << "\nWhere do you want to go?\n\n0. Quit\n1. Main Hall\n2. Laundry Room\n3. Library\n4. Kitchen\n5. Bedroom\n6. Dining Room\n" << endl;
        cin >> userIn;
        
        switch (userIn)
        {
        case 0:
            
            break;

        case 1:                                                         // Updates the players current room object to the room hes in and 
            player.move(rooms[0]);                                      //shows the player is in the room with boolean update
            rooms[0].setPlayer(true); 
            player.setRoom(rooms[0].getName()) ;             
            return player;  
            break;

        case 2:
            player.move(rooms[1]);
            rooms[1].setPlayer(true);
            player.setRoom(rooms[1].getName()); 
            return player;  

            break;        
        case 3:
            player.move(rooms[2]);
            rooms[2].setPlayer(true);
            player.setRoom(rooms[2].getName());  
            return player;    
            break;        

        case 4:
            player.move(rooms[3]);
            rooms[3].setPlayer(true);
            return player;    
            break; 

        case 5:
            player.move(rooms[4]);
            rooms[4].setPlayer(true);
            return player;     
            break;  

        case 6:
            player.move(rooms[5]);
            rooms[5].setPlayer(true); 
            return player;    
            break; 

        default:
            cout << "invalid input" << endl;
            break;
        }

        

    }
    return player;

}




PI gameDriver::searchRoom( Room  room, PI player){                                  //used to find items in the room the player is currently in
int userIn = 1;
int userIn2 = 1;



if(room.getItem().getname() != "empty"){                                               //makes sure room isnt empty
cout << "   ~You've found a :" << room.getItem().getname() << "\n" <<  endl;

while (userIn != 0)
{
    cout << "   ~What do you want to do with: " << room.getItem().getname() << "?\n\n0. Quit\n1. Inspect\n2. Take" << endl;
    cin >> userIn ;

    switch (userIn)
    {
    case 0:
        
        break;

    case 1:
        cout << "\n\n   ##" << room.getItem().getname() << "-\n" << room.getItem().getDetail() << "\n\n" << endl;                   //shows what item is being looked at
            while (userIn2 != 0)
            {
                cout << "\n0. Back\n1. Write this down\n" << endl;
                cin >> userIn2;

                switch (userIn2)
                {
                case 0:
                    
                    break;

                case 1:
                    player.writeDown(room.getItem());                                               //calls writeDown function with item so its detain can be added to notebook
                    cout << "   ##This has been written down" << endl;
                    break;

                default:
                    cout << "invlaid input" << endl;
                    break;
                }
                
            }
        break;

    case 2:
        player.takeItem(room.getItem());
        cout << "  ##" << room.getItem().getname() << " has been taken\n" << endl;                  //takes item from the room and adds to player inventory
        for(int i = 0; i < rooms.size(); i++){
            if (rooms[i].getName() == room.getName())
            {
                rooms[i].setItem("empty");                                                          //updates rooms item object to empty so it won't be accessible anymore
                player.move(rooms[i]);
            }
            
        }
        
        
        userIn = 0;
        break;
        
    
    default:
        cout << "invalid input" << endl;
        break;
    }
    /* code */
}


return player;
}

else{
    cout << "\n\n   ~The " <<room.getName() << " is empty." << endl;                         //if room is empty player state is not updated and returned as is
    return player;
}

}


void gameDriver::gameResult(int num){                                                        //writes the result of game as based on return of accuse function and writes it to a file
  cout << "\n\n ##CHECK gameResults.txt file for outcome of game\n\n";
  ofstream myfile;
  myfile.open ("gameResult.txt");
 
  
    if(num == 9){
        myfile << "Detective - Through interviewing everyone here and searching through the rooms, \nI can conclude the killer is Mrs. Smift. \nThe murder weapon was found in the kitchen a knife covered in blood, I had noticed it was worn down on the handle near the 3rd notch which correlates to the engagment ring Mrs. Smift was wearing.\n Her motive I discovered through the letter found in the dinning room which revealed Master was planing to stop funding their wedding ceremony\n and the entry in Master's diary which stated his suspicion of infidelity in Mr. and Mrs. Smifts relation ship. Take her away!";  
        myfile << "\n\n#### Congragulations you've won   #####\n";
    }

    else{
        myfile << "\n\n   ~I hate to inform you but youre decision was WRONG either you chose the wrong individual or \nyou didn't collect enought evidence for it to hold up in court\n\n###FAIL  GAME OVER ####\n###TRY AGAIN ###";
    }
    myfile.close();
    exit(0);                                                //ends program

}



void gameDriver::runGame(){                         //main driver behind game functions and main menu
    string userInS;
    int userIn = 1;
    int ans = 0;
    
    popItems("Items.txt");
    popRooms("Rooms.txt");
    popRoles("Roles.txt");



    for(int i =0; i< roles.size(); i++){
        rooms[0].setOccupant(roles[i]);
    }


    cout <<"\n\n   ~Whats your last name?" << endl;
    cin >> userInS;

    
    PI player = PI(userInS);
    cout << "   ~" << player.getName() << ", you have been called to the Mansion of ~Master~ to solve his mysterious death.\nInterview the guests at his house and travel througth rooms to collect clues to solve the case.\n\n";
    
    cout << "\n   Police Cheif: hello detective "<< player.getName()<<", we need your help solving this murder, I've gathered every one who was in the house in the main hall for quesitoning."  << endl;
    cout << "       ---------    " << endl;
    cout << "       |||||||||___    "<<endl;
    cout << "       | ^   ^ |    " << endl;
    cout << "      @ (o) (o) @   " << endl;
    cout << "       |   <   |  " << endl;
    cout << "       | ~___~ |  " << endl;
    cout << "        \\_____/  " << endl;
    cout << "     ____|  |____  " << endl;
    cout << "    /    \\__/    \\  " << endl;
    cout << "   /          *   \\  " << endl;
    cout << "  /\\_/|        |\\_/\\  " << endl;
    cout << " / /  |        |  \\ \\  " << endl;
    cout << "( <   |        |   > )  " << endl;
    cout << " \\ \\  |        |  / /  " << endl;
    cout << "  \\ \\ |________| / /  " << endl;
 
    player.move(rooms[0]);
    rooms[0].setPlayer(true);

    while (userIn != 0)
    {
        cout << "\n##Action Menu##:\n\n0. Quit\n1. Change Room\n2. Survey Room\n3. Search Room\n4. Look at notebook\n5. Inventory\n6. Question\n7. Accuse someone" << endl;
        cin >> userIn;
        
        switch (userIn)
        {
        case 0:
            cout << "\n~you have left the game\n\n" << endl;
            exit(0);
            break;

        case 1:
            player = changeRoom(player);                                                    //calls change room funciton to move player around the map
            break;
        
        case 2:
            cout << "\n   ~you are in the  " << player.getRoom() << endl;                   //prints out what room the player currently is in
            cout << "\n   ~with: " << player.getCurrRoom().getCharacterList();
            cout << "\n\n" << endl;
            break;

        case 3:
            player = searchRoom(player.getCurrRoom(), player);                              //calls search room function to find items in room based on what room the player is in currently
            break;

        case 4:
            cout << "\n##NOTEBOOK:\n\n" << endl;
            for (int i =0; i < player.getNotebook().size(); i++ ){                          //prints out what has been added to notebook vector ie whats been written down
                cout << player.getNotebook()[i] << endl;
            }
            break;
        case 5:
            cout << "\n##INVENTORY:\n" << endl;
                for (int i = 0; i < player.getInventory().size(); i++){                     //prints out what has been added to inventory vector ie whats been taken
                    cout << "-" << player.getInventory()[i].getname() << endl;
                }
            break;
        case 6:
            if(player.getCurrRoom().getOccupants().size()>0){                               //prints out who is in the room with the player
            player.question(player.getCurrRoom().getOccupants());}

            else{
                cout << "   ~No one is in the room\n" << endl;
            }
            break;
        
        case 7:
            ans =  player.accuse(roles, player);                                                // calls accuse function to end game and produce either a win or loss
            if( (ans) == 0){
                break;
            }
            else{
                gameResult(ans);

            }

            userIn = 0;
            break;
            


        default:
            cout << "invalid input" << endl;
            break;
        }
        
       
    }
    
    


}

gameDriver::gameDriver(){
    name = "game";
}



