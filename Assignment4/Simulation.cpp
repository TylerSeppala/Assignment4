//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4

//Implementation of simulation class, moves students from line to windows and calculates metrics 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(string file)//constructor to initialize variables and create queue
{
  filename = file;
  totalStudents = 0;
  timesIndex = 0;
  time = 0;
  maxWindowIdle = 0;
  idleOverFive = 0;
  studentLine = new ListQueue<Student>;
}

Simulation::~Simulation()//destructor to delete the two arrays used
{
  delete []windows;
  delete []timesWaited;
}

void Simulation::fillLine()//method to extract data from file and fill student line
{
  string line;
  ifstream read_file (filename);

  if (read_file.is_open())
  {
    getline(read_file,line);
    windowsOpen = stoi (line,nullptr,0);//determines number of open windows from file
    while (getline(read_file,line))
    {
      minuteArrived = stoi (line, nullptr,0);//determines minute the current group of students arrived from file
      getline(read_file,line);
      numStudents = stoi (line,nullptr,0);//determines number of students who arrived at given time
      for (int i = 0; i < numStudents; i++)//creates students and adds them to line based on their arrival time
      {
        getline(read_file,line);
        studentLine->insert(Student(minuteArrived, stoi (line,nullptr,0)));
        totalStudents++;
      }
    }
  }
}

void Simulation::simulate()//method to simulate the movement of students from line to windows
{//initialize arrays
  windows = new Window[windowsOpen];
  timesWaited = new int[totalStudents];
  while (!studentLine->isEmpty())//loop that keeps program going until there are no more students
  {
    for (int i = 0; i < windowsOpen; i++)//checks each open window
    {
      //cout << studentLine.front().minuteArrived << endl;
      if (!studentLine->isEmpty() && studentLine->front().minuteArrived <= time && windows[i].available)//checks if there is an open window and a student currently in the line to go to that window
      {
        if (windows[i].idleTime > maxWindowIdle)//finds longest window idle time
          maxWindowIdle = windows[i].idleTime;
        if (windows[i].idleTime > 5)//finds number of windows with idle time more than five minutes
          idleOverFive++;
        student = studentLine->remove();//student leaves line
        windows[i] = Window(student);//student goes to window
        windows[i].timeWaited = (time - student.minuteArrived);//determines amount of time current student waited
        timesWaited[timesIndex] = windows[i].timeWaited;//adds student wait time to array
        timesIndex++;//advances position in array
      }
      else if (windows[i].available)//checks if window is idle at current time
      {
        totalWindowIdle++;
        windows[i].idleTime++;
      }
      else//decreases amount of time student in front of line has to wait until window is empty
      {
        windows[i].waitTime--;
      }

      if (windows[i].waitTime == 0)//declares window availabe once student is finished
      {
        windows[i].available = true;
      }
      if (studentLine->isEmpty())//runs final window check once line is empty
      {
        if (windows[i].idleTime > maxWindowIdle)
          maxWindowIdle = windows[i].idleTime;
        if (windows[i].idleTime > 5)
          idleOverFive++;
      }
    }
    time++;//adcances time one minute
  }
}

void Simulation::getMetrics()//method to calculate metrics on students and windows
{
  double meanWait;//mean student wait time
  double timeCounter = 0;//total amount of time waited by students
  double medianWait;//median student wait time
  int longestWait = 0;//longest student wait time
  int waitOverTen = 0;//amount of students who waited over ten minutes
  double meanWindowIdle;//mean window idle time

  for (int i = 0; i < totalStudents; i++)//iterates through student wait times
  {
    timeCounter += (double)timesWaited[i];
    if (timesWaited[i] > longestWait)//determines longest wait time
      longestWait = timesWaited[i];
    if (timesWaited[i] > 10)//determines amount of students who waited over ten minutes
      waitOverTen++;
  }
  meanWait = (timeCounter / (double)totalStudents);//calculates mean student wait time

  sort(timesWaited, timesWaited + totalStudents);//orders student wait times from least to greatest

  //claculates median student wait time
  if (totalStudents % 2 != 0)
    medianWait = (double)timesWaited[totalStudents/2];
  else
    medianWait = (double)(timesWaited[(totalStudents-1)/2] + timesWaited[totalStudents/2])/2.0;

  meanWindowIdle = totalWindowIdle / (double)windowsOpen;//calculates mean window idle time

  //Output metrics to console
  cout << endl;
  cout << "Student Metrics:" << endl;
  cout << "-------------------------" << endl;
  cout << "Mean student wait time: " << meanWait << endl;
  cout << "Median student wait time: " << medianWait << endl;
  cout << "Longest student wait time: " << longestWait << endl;
  cout << "Number of students who waited over ten minutes: " << waitOverTen << endl;
  cout << endl;
  cout << "Window Metrics:" << endl;
  cout << "-------------------------" << endl;
  cout << "Mean window idle time: " << meanWindowIdle << endl;
  cout << "Longest window idle time: " << maxWindowIdle << endl;
  cout << "Number of windows idle for over five minutes: " << idleOverFive << endl;
  cout << endl;
}
