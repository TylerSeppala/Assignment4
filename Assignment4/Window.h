//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4

//Header to window class, stores data about each window

#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
public:
  Window();
  Window(Student st);

  bool available;//wheter or not there is a student at window
  int waitTime;//remaining wait time until window is availabe
  int timeWaited;//time that current student at window waited before getting there
  int idleTime;//amount of time window has been empty 
};
