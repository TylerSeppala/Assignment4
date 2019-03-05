//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//Stores variable values of world class 

#include <iostream>

using namespace std;

class World
{
public:
  World(int width, int height, double density);
  World(string path);
  ~World();

  void buildArray(int width, int height);
  void randomFill();
  void fileFill(string path);
  void display();
  void writeFile(string fileName);
  bool isEmpty();

  int _generation;
  int _width;
  int _height;
  double population_density;

  char **currentMap;
};
