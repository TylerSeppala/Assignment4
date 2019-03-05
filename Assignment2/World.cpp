//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//Class for the building and handling of a world map

#include "World.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

World::World(int width, int height, double density)//initializes world randomly based on user input
{
  buildArray(width, height);
  _width = width;
  _height = height;
  _generation = 0;
  population_density = density;
  randomFill();
}

World::World(string path)//initializes world based on a map file
{
  string line;
  _generation = 0;
  ifstream read_file (path);
  getline (read_file, line);
  _height = stoi(line);
  getline (read_file, line);
  _width = stoi(line);
  buildArray(_width, _height);
  fileFill(path);
}

World::~World()//deletes world map when it falls out of scope
{
  for (int i = 0; i < _height; i++)
  {
    delete []currentMap[i];
  }
  delete []currentMap;
}

void World::buildArray(int width, int height)//assigns an array pointer to each member of array (creates 2d array)
{
  currentMap = new char*[height];
  for(int i = 0; i < height; ++i)
  {
    currentMap[i] = new char[width];
  }
}

void World::randomFill()//Randomly assigns array values based on input density
{
  srand(time(0));
  double rando;
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      rando = ((double) rand() / (RAND_MAX));
      if (rando < population_density)
      {
        currentMap[i][j] = 'X';
      }
      else
      {
        currentMap[i][j] = '-';
      }
    }
  }
}

void World::fileFill(string path)//assigns array values from map file
{
  string line;
  ifstream read_file (path);
  getline (read_file, line);
  getline (read_file, line);
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      read_file >> currentMap[i][j];
    }
  }
}

bool World::isEmpty()//returns true if all values in array are '-'
{
  int xCount = 0;
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (currentMap[i][j] == 'X')
      {
        xCount++;
      }
    }
  }
  if (xCount == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void World::display()//prints world map to console
{
  cout << endl;
  cout << _generation << endl;
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      cout << currentMap[i][j];
    }
    cout << endl;
  }
}

void World::writeFile(string fileName)//writes world map to file 
{
  ofstream write_file;
  write_file.open (fileName, std::ios_base::app);
  write_file << endl;
  write_file << _generation << endl;
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      write_file << currentMap[i][j];
    }
    write_file << endl;
  }
  write_file.close();
}
