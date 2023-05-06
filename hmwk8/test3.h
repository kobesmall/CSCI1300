





#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include <vector>


using namespace std;


class University
{

private:
string universityName;
vector <double> StudentGPA;
vector <string> StudentName;


public:
University();
University(string name);
bool AddStudent(string name, double gpa);
double CalcAvgGPA();
double getMaxGPA();
int CountSameNames(string name);




};



#endif


