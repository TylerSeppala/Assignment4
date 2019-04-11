#include <iostream>

using namespace std;

template <class X>
class ListNode
{
public:
  ListNode (const X &e = X(), ListNode *n = NULL, ListNode *p = NULL) : data(e), next(n), prev(p) {}
  ~ListNode() {}
  X data;
  ListNode *next;
  ListNode *prev;
};
