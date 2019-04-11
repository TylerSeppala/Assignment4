//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4

//Header class to simulation class, which stores data necessary to simulate moving of students

#include <iostream>
#include <fstream>
#include "Window.h"
#include "ListQueue.h"

using namespace std;

class Simulation
{
public:
  Simulation(string file);
  ~Simulation();

  void fillLine();
  void simulate();
  void getMetrics();

  string filename;//name of file containing initialization data
  int windowsOpen;//amount of open windows at start of simulation
  int minuteArrived;//stores the minute at which the current group of students arrived
  int numStudents;//number of students that arrived at the given minute
  int totalStudents;//total amount of students that vistied the office
  int timesIndex;//used to iterate through an array of student wait times
  int time;//current time in the office
  double totalWindowIdle;//total amount of time all windows have spent idle
  int maxWindowIdle;//longest any window has spent idle
  int idleOverFive;//amount of windows that have idled for over five minutes
  Student student;//current student that is approaching a window

  ListQueue<Student> *studentLine;//Queue that represents line for windows
  Window *windows;//Array that represents all the open windows
  int *timesWaited;//Array that holds all the students' wait times 
};
