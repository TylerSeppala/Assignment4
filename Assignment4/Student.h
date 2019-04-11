//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4 (Registrar's Office)

//Header to student class, which stores when each student arrived and how much time they need

#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int min, int time);

  int minuteArrived;//Stores the clock-tick at which the student entered the line
  int timeNeeded;//Stores the amount of time the student 
};
