//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 3 (Syntax Checker)

//Class to check if delimiters match and return error locations

#include <iostream>
#include <fstream>
#include <string.h>
#include "DelimCheck.h"
#include "GenStack.h"

using namespace std;

DelimCheck::DelimCheck(string file)
{
  filename = file;
  line;
  delimCount = 0;
  currentLine = 0;
  countDelims();
  checkDelims();
}

void DelimCheck::countDelims()
{
  ifstream read_file (filename);
  if (read_file.is_open())
  {
    while ( getline (read_file,line) )//iterates through each line of file
    {
      for (int i = 0; i <= line.length(); i++)
      {
        if (line[i] == '{' || line[i] == '[' || line[i] == '(')//counts opening delimiters
        {
          delimCount++;
        }
      }
    }
  }
  read_file.clear();
  read_file.seekg(0, ios::beg);//resets cursor to beginning of file
}

void DelimCheck::checkDelims()
{
  ifstream read_file (filename);
  GenStack<string> delimStack(delimCount);//creates stack to hold opening delimiters
  int i;
  try
  {
    if (read_file.is_open())
    {
      while ( getline (read_file,line) )
      {
        currentLine++;
        for (i = 0; i <= line.length(); i++)
        {
          if (line[i] == '{' || line[i] == '[' || line[i] == '(')//adds opening delimiters to stack
          {
            delimStack.push(line[i] + to_string(currentLine));
          }
          else if (line[i] == '}' && delimStack.peek()[0] == '{')//removes opening delim from stack if it matches closing delim
          {
            delimStack.pop();
          }
          else if (line[i] == ']' && delimStack.peek()[0] == '[')//""
          {
            delimStack.pop();
          }
          else if (line[i] == ')' && delimStack.peek()[0] == '(')//""
          {
            delimStack.pop();
          }
          else if (line[i] == '}' || line[i] == ']' || line[i] == ')')
          {
            if (delimStack.peek()[0] == '{')//returns location of error involving "{}"
            {
              cout << "Error at " << currentLine << endl;
              cout << "Expected '" << match(delimStack.peek()[0]) << "'" << endl;
            }
            else//returns location of error involving "()" or "[]"
            {
              cout << "Error at " << delimStack.peek().substr(1,-1) << endl;
              cout << "Expected '" << match(delimStack.peek()[0]) << "'" << endl;
            }
            exit(EXIT_FAILURE);
          }
        }
      }
    }
    if (!delimStack.isEmpty())//Identifies a missing delimiter

    {
      cout << "Reached end of file, missing '" << match(delimStack.peek()[0]) << "'." << endl;
      exit(EXIT_FAILURE);
    }
  }
  catch (out_of_range)//Identifies extra delimiter
  {
    cout << "Reached end of file, found extra '" << line[i] << "'." << endl;
    exit(EXIT_FAILURE);
  }
}

char DelimCheck::match(char d)
{
  switch (d)
  {
    case '{':
      return '}';
      break;
    case '(':
      return ')';
      break;
    case '[':
      return ']';
      break;
  }
}
