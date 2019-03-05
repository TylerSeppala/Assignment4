//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//stores variable values for mode class 

#include <iostream>
#include "World.h"
#include "UserIn.h"

using namespace std;

class Mode
{
public:
  Mode(World map, UserIn userIn);
  ~Mode();

  void buildArray(int width, int height);
  void classicGen();
  void mirrorGen();
  void doughnutGen();
  void display();
  void writeCopy(int i, int j);
  void copyBack();

  string modeType;
  int _height;
  int _width;
  int neighborCount;
  char **ogMap;
  char **mapCopy;
};
