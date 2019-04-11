//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4 (Registrar's Office)

//Implementation of student class

#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()//default constructor
{
  minuteArrived = 0;
  timeNeeded = 0;
}

Student::Student(int min, int time)//constructor for a known student 
{
  minuteArrived = min;
  timeNeeded = time;
}
