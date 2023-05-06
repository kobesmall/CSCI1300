#include <iostream>


using namespace std;


void print3Pointers(string tm[], int pts[], int size){

        for(int i=0; i<size; i++){

            if(pts[i] < 500 || pts[i] > 800){
                cout << tm[i] << " " << pts[i] << endl;
            }
        }
          


 return;
}

int main(){
string tms[] = {"Lakers", "Nuggets", "Heat", "Celtics"};
int pts[] = {500, 400, 600, 900};
int size = 4;


print3Pointers(tms,pts,size);


return 0;
}