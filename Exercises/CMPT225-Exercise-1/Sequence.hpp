#include <iostream>
using namespace std;

class Sequence
{
  struct Node{
    int data;
    Node * next;
  };
  Node * first;
  Node * last;
public:
  Sequence();
  void insert(double x);
  void clear();
  int size();
  double stdDeviation();
};
