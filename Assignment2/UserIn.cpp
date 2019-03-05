//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//Deals with prompting and user input for program

#include "UserIn.h"
#include "World.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

UserIn::UserIn()//runs prompts in succession upon construction 
{
  initialPrompt();
  modePrompt();
  outputPrompt();
}

UserIn::~UserIn()
{

}

void UserIn::initialPrompt()//gives prompts and collects necessary input to start program
{
  cout << endl;
  cout << "Welcome to the Game of Life." << endl;
  cout << "----------------------------" << endl;
  cout << endl;
  cout << "Would you like a randomly generated world (r) or would you like to \nprovivde a map file (f)? ";
  cin >> mapChoice;
  for (int i = 0; i < 1; i++)
  {
    mapChoice = tolower(mapChoice[i]);//converts input value to lowercase to avoid error
  }

  while(true)
  {
    if (mapChoice == "r")
    {
      cout << "Enter the desired height of the map: ";
      cin >> heightIn;
      if (!isdigit(heightIn[0]))//error checking
      {
        cout << "Invalid input." << endl;
        heightIn = 1;
        continue;
      }
      height = stoi(heightIn);//parses input to int
      cout << "Enter the desired width of the map: ";
      cin >> widthIn;
      if (!isdigit(widthIn[0]))//error checking
      {
        cout << "Invalid input." << endl;
        width = 1;
        continue;
      }
      width = stoi(widthIn);//parses input to int
      cout << "Enter the desired starting population density (value between 0 and 1): ";
      cin >> densityIn;
      try
      {
        density = stod(densityIn);//error checking and parse input to double
        break;
      }
      catch (std::invalid_argument e)
      {
        cout << "Invalid input." << endl;
        continue;
      }
    }
    else if (mapChoice == "f")
    {
      cout << "Enter the name of the map file: ";
      cin >> fileName;

      if (FILE *file = fopen(fileName.c_str(), "r"))//checking if file exists
      {
        fclose(file);
        break;
      }
      else
      {
        cout << "File not found." << endl;
        continue;
      }
    }
    else
    {
      cout << "Invalid input. Please type 'r' for a randomly generated world or 'f' for a map file: ";
      cin >> mapChoice;
    }
  }
}

void UserIn::modePrompt()//prompt for input regarding preferred boundary mode
{
  cout << "Please select a mode for boundary-handling. Type:\n\tC for classic mode\n\tD for doughnut mode\n\tM for mirror mode";
  while (true)
  {
    cout << endl;
    cin >> mode;
    for (int i = 0; i < 1; i++)
    {
      mode = tolower(mode[i]);
    }
    if (mode == "c" || mode == "d" || mode == "m")
    {
      break;
    }
    else
    {
      cout << "Invalid Entry. Type:\n\tC for classic mode\n\tD for doughnut mode\n\tM for mirror mode";
    }
  }
}

void UserIn::outputPrompt()//prompt user for input regarding preferred form of output
{
  cout << endl;
  cout << "Select your desired means of output. Type:\n\tE to press enter to display each generation in the console\n\tP for a pause for each generation displayed to the console\n\tF to output up to 1000 generations to a file.";
  while (true)
  {
    cout << endl;
    cin >> outputType;
    for (int i = 0; i < 1; i++)
    {
      outputType = tolower(outputType[i]);
    }
    if (outputType == "f")
    {
      cout << endl;
      cout << "Enter the name of the file you would like to output to: ";
      cin >> outFile;
      break;
    }
    else if (outputType == "e" || outputType == "p")
    {
      break;
    }
    else
    {
      cout << endl;
      cout << "Invalid Entry. Type:\n\tE to press enter to display each generation in the console\n\tP for a pause for each generation displayed to the console\n\tF to output up to 1000 generations to a file." << endl;
    }
  }
}
