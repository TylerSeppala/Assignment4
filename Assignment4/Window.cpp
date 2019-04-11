#include <iostream>
#include "Window.h"

using namespace std;

Window::Window()//default constructor
{
  available = true;
  waitTime = 0;
  timeWaited = 0;
  idleTime = 0;
}

Window::Window(Student st)//constructor for window with a new student 
{
  available = false;
  waitTime = st.timeNeeded;
  timeWaited = 0;
  idleTime = 0;
}
