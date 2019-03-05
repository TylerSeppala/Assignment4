//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//stores variable values of UserIn class 

#include <iostream>

using namespace std;

class UserIn
{
public:
  UserIn();
  ~UserIn();

  string mapChoice;
  string fileName;
  string mode;
  string outputType;
  string outFile;
  string displayChoice;
  string heightIn;
  string widthIn;
  string densityIn;
  int height;
  int width;
  double density;

  void initialPrompt();
  void modePrompt();
  void outputPrompt();
};
