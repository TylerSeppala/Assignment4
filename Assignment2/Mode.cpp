//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 2 (Game of Life)

//class for carrying out selected mode of map generation

#include <iostream>
#include <unistd.h>
#include "Mode.h"

using namespace std;

Mode::Mode(World map, UserIn userIn)//takes starting map and userIn values to run program
{
  //copies info about starting map to create secondary ghost map
  _height = map._height;
  _width = map._width;
  ogMap = map.currentMap;
  buildArray(_width, _height);
  //calculate each generation and display based on user's choices
  while (!map.isEmpty())
  {
    if (userIn.mode == "c")
    {
      classicGen();
    }
    else if (userIn.mode == "d")
    {
      doughnutGen();
    }
    else
    {
      mirrorGen();
    }
    copyBack();
    map._generation++;
    if (userIn.outputType == "e")
    {
      map.display();
      cin.get();
    }
    else if (userIn.outputType == "p")
    {
      map.display();
      sleep(1);
    }
    else
    {
      if (map._generation <= 1000)
      {
        map.writeFile(userIn.outFile);
      }
      else
      {
        break;
      }
    }
  }
}

Mode::~Mode()//deletes ghost map
{
  for (int i = 0; i < _height; i++)
  {
    delete []mapCopy[i];
  }
  delete []mapCopy;
}

void Mode::buildArray(int width, int height)//creates 2d ghost array
{
  mapCopy = new char*[height];
  for(int i = 0; i < height; ++i)
  {
    mapCopy[i] = new char[width];
  }
}

void Mode::classicGen()//code for generating maps in classic mode
{
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (i == 0)
      {
        if (j == 0)//top left corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//top right corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else//top edge
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else if (i == _height - 1)
      {
        if (j == 0)//bottom left corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//bottom right corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else//bottom edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else
      {
        if (j == 0)//left edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//right edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else//middle
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      //cout << neighborCount << endl; (testing purposes)
      writeCopy(i, j);
    }
  }
}

void Mode::mirrorGen()//code for generating maps in mirror mode
{
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (i == 0)
      {
        if (j == 0)//top left corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i + 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount += 3;
          }
        }
        else if (j == _width - 1)//top right corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i + 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount += 3;
          }
        }
        else//top edge
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else if (i == _height - 1)
      {
        if (j == 0)//bottom left corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i - 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount += 3;
          }
        }
        else if (j == _width - 1)//bottom right corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i - 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount += 3;
          }
        }
        else//bottom edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else
      {
        if (j == 0)//left edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//right edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount += 2;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j] == 'X')
          {
            neighborCount++;
          }
        }
        else//middle
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      //cout << neighborCount << endl; (testing purposes)
      writeCopy(i, j);
    }
  }
}

void Mode::doughnutGen()//code for generating maps in doughnut mode
{
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (i == 0)
      {
        if (j == 0)//top left corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][_width - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//top right corner
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][0] == 'X')
          {
            neighborCount++;
          }
        }
        else//top edge
        {
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[_height - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else if (i == _height - 1)
      {
        if (j == 0)//bottom left corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1] [j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][_width - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//bottom right corner
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1] [j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][j - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else//bottom edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[0][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      else
      {
        if (j == 0)//left edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][_width - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][_width - 1] == 'X')
          {
            neighborCount++;
          }
        }
        else if (j == _width - 1)//right edge
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][0] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][0] == 'X')
          {
            neighborCount++;
          }
        }
        else//middle
        {
          if (ogMap[i - 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i - 1][j + 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j - 1] == 'X')
          {
            neighborCount++;
          }
          if (ogMap[i + 1][j + 1] == 'X')
          {
            neighborCount++;
          }
        }
      }
      //cout << neighborCount << endl; (testing purposes)
      writeCopy(i, j);
    }
  }
}

void Mode::writeCopy(int i, int j)//fills ghost array based on neighbors per index
{
  if (neighborCount <= 1)
  {
    mapCopy[i][j] = '-';
  }
  else if (neighborCount == 2)
  {
    mapCopy[i][j] = ogMap[i][j];
  }
  else if (neighborCount == 3)
  {
    mapCopy[i][j] = 'X';
  }
  else
  {
    mapCopy[i][j] = '-';
  }
  neighborCount = 0;
}

void Mode::copyBack()//copies ghost array back to current array
{
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      ogMap[i][j] = mapCopy[i][j];
    }
  }
}

void Mode::display()//displays ghost array (testing purposes)
{
  cout << "Copy:" << endl;
  for (int i = 0; i < _height; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      cout << ogMap[i][j];
    }
    cout << endl;
  }
}
