//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 3 (Syntax Checker)

//Main class that runs the delimiter check and asks user if they want to check
//another file

#include <iostream>
#include <fstream>
#include "DelimCheck.h"

using namespace std;

int main (int argc, char **argv)
{
  string file = argv[1];//assigns command line argument to variable 
  char continuing;
  while (true)
  {
    DelimCheck delimCheck(file);//checks delimiters for errors
    cout << "No delimiter errors detected. Do you want to process another file? (y/n):" << endl;//asks if user wants to continue
    cin >> continuing;
    if (continuing == 'y')
    {
      cout << "Please enter the filename:" << endl;//takes name of new file for evaluation
      cin >> file;
      if (FILE *filePointer = fopen(file.c_str(), "r"))//checking if file exists
      {
        fclose(filePointer);
        continue;
      }
      else
      {
        cout << "File not found." << endl;
        break;
      }
    }
    break;
  }
  return 0;
}
