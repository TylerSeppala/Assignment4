//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

#include "Mode.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  UserIn userIn;
  if (userIn.mapChoice == "r")//runs program for randomly generated map
  {
    World randWorld(userIn.width, userIn.height, userIn.density);
    randWorld.display();
    Mode currentMode(randWorld, userIn);
  }
  else//runs program for map file 
  {
    World fileWorld(userIn.fileName);
    fileWorld.display();
    Mode currentMode(fileWorld, userIn);
  }

  return 0;
}
