//Tyler Seppala
//2297817
//seppala@chapman.edu
//CPSC 350-02
//Assignment 4 (Registrar's Office)

//Template class for a doubly linked list

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class X>
class GenList
{
private:
  ListNode<X> *front;
  ListNode<X> *back;
  unsigned int size;

public:
  GenList();
  ~GenList();
  void insertFront(X d);
  void insertBack(X d);
  X removeFront();
  X removeBack();
  X remove(int key);
  void printList();
  int find(X val);//aka search()
  bool isEmpty();
  unsigned int getSize();
  X getFront();
};

//Implementation
template <class X>
GenList<X>::GenList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class X>
GenList<X>::~GenList()
{
  ListNode<X>* current = front;
  while (current != NULL)
  {
    ListNode<X>* next = current->next;
    delete current;
    current = next;
  }
  front = NULL;
}

template <class X>
unsigned int GenList<X>::getSize()
{
  return size;
}

template <class X>
X GenList<X>::getFront()
{
  return front->data;
}

template <class X>
void GenList<X>::printList()
{
  ListNode<X> *curr = front;
  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class X>
int GenList<X>::find(X val)
{
  int idx = -1;
  ListNode<X> *curr = front;
  while (curr != NULL)
  {
    ++idx;
    if (curr->data == val)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }
  if (curr == NULL)
  {
    idx = -1;
  }
  return idx;
}

template <class X>
void GenList<X>::insertFront(X data)
{
  ListNode<X> *node = new ListNode<X>(data);

  if (size == 0)
  {
    back = node;
  }
  else//not empty
  {
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <class X>
void GenList<X>::insertBack(X data)
{
  ListNode<X> *node = new ListNode<X>(data);

  if (size == 0)
  {
    front = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class X>
X GenList<X>::removeFront()
{
  //check if empty
  ListNode<X> *node = front;

  //check if only one element
  if (front->next == NULL)
  {
    back = NULL;
  }
  else//more than one element
  {
    front->next->prev = NULL;
  }
  front = front->next;
  X temp = node->data;
  node->next = NULL;
  delete node;
  size--;

  return temp;
}

template <class X>
X GenList<X>::removeBack()
{
  ListNode<X> *node = back;

  if (back->prev == front)
  {
    front = NULL;
  }
  else
  {
    back->prev->next = NULL;
  }
  back = back->prev;
  X temp = node->data;
  node->prev = NULL;
  delete node;
  size--;

  return temp;
}

template <class X>
X GenList<X>::remove(int key)
{
  //could call find() here
  //lets search manually
  ListNode<X> *curr = front;

  while (curr->data != key)
  {
    curr = curr->next;
    if (curr == NULL)
    {
      return curr->data;
    }
  }

  if (curr == front)
  {
    front = curr->next;
  }
  else
  {
    curr->prev->next = curr->next;
  }

  if(curr == back)
  {
    back = curr->prev;
  }
  else
  {
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  size--;
  X temp = curr->data;
  delete curr;
  return temp;//or delete curr or return value
}

template <class X>
bool GenList<X>::isEmpty()
{
  return (size == 0);
}
