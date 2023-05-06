




#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



class Book
{
    private:
        string name;
        string author;
        int orders = 0;
    public:
        Book();
        Book(string name, string author, int order);
        string getName();
        void setName(string name);
        string getAuthor();
        void setAuthor(string author);
        int getOrders();
        void setOrders(int order);
        double grossRevenue(double price);


};

Book::Book(){
    name="";
    author = "";
    orders = 0;

}

Book::Book(string nm,string au, int ord){
    name = nm;
    author = au;
    orders = ord;
}

string Book::getName(){
    return name;
}

void Book::setName(string nm){
    name = nm;
}

string Book::getAuthor(){
    return author;
}

void Book::setAuthor(string au){
    author = au;
}

int Book::getOrders(){
    return orders;
}

void Book::setOrders(int ord){
    orders = ord;
}

double Book::grossRevenue(double price){
    return price * orders;
}


class SynonymDictionary
{
    private:
        string words[50];
        string synonym[50];
    public:
        SynonymDictionary();
        int LoadWords(string filename);
        int SearchForWord(string wordName);
        string GetSynonym(string wordName);

};

SynonymDictionary::SynonymDictionary(){
    
}

int SynonymDictionary::LoadWords(string filename){
ifstream in1;
in1.open(filename);
string line;
string linesplit[2];

if (in1.fail()){                             
        
     
      return -1;
}
int i = 0;
while (getline(in1, line)) {                
    
     if(!line.empty()){                       
         split(line, ',',linesplit,2);   
         words[i] = linesplit[0];
         synonym[i] = linesplit[1];
         i++;
        }   
    }
return 0;
}

int SynonymDictionary::SearchForWord(string word){

    for (int i =0; i<50; i++){
        if(word == words[i]){
            return i;
        }
    }
    return -1;
}

string SynonymDictionary::GetSynonym(string word){
int index=0;

    index = SearchForWord(word);

    if(index == -1){
        return "";

    }
    else{
        return synonym[index];
    }


}