#include <iostream>
#include "GenList.h"

using namespace std;

template <class X>
class ListQueue
{
public:
  ListQueue();//default constructor
  ~ListQueue();

  void insert(X d);//enqueue
  X remove();//dequque()
  X front();//peek()

  bool isFull();
  bool isEmpty();
  int getSize();

private:
  int numElements;//amount of elements in queue

  GenList<X> *myQueue;//data structure
};

template <class X>
ListQueue<X>::ListQueue()
{
  myQueue = new GenList<X>;
  numElements = 0;
}

template <class X>
ListQueue<X>::~ListQueue()
{
  delete myQueue;
}

template <class X>
void ListQueue<X>::insert(X d)
{
  myQueue->insertBack(d);
  ++numElements;
}

template <class X>
X ListQueue<X>::remove()
{
  //error checking/bounds/isEmpty
  X c;
  if (!myQueue->isEmpty())
  {
    c = myQueue->removeFront();
    numElements--;
  }
  else
  {
    cout << "Queue empty." << endl;
  }

  return c;
}

template <class X>
X ListQueue<X>::front()
{
  return myQueue->getFront();
}

template <class X>
bool ListQueue<X>::isEmpty()
{
  return (numElements == 0);
}

template <class X>
int ListQueue<X>::getSize()
{
  return numElements;
}
