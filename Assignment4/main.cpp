//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4 (Registrar's Office)

//Main class which collects input file and initializes simulation 

#include <iostream>
#include "Simulation.h"

using namespace std;

int main (int argc, char **argv)
{
  string file = argv[1];
  Simulation simulation(file);
  simulation.fillLine();
  simulation.simulate();
  simulation.getMetrics();

  return 0;
}
