//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 3 (Syntax Checker)

//Header class to store variables for DelimCheck

#include <iostream>

using namespace std;

class DelimCheck
{
public:
  DelimCheck(string file);

  string filename;//name of file being checked
  string line;//line of file being evaluated
  int delimCount;//total number of opening delimiters in file
  int currentLine;//current line in file being evaluated

  void countDelims();//determines size of stack
  void checkDelims();//checks if delimiters match and returns error locations
  char match(char d);//returns matching closing delimiter for each opening delimiter
};
