#include <iostream>
#include <string.h>
using namespace std;

class deque {
public:

  struct Student {
    string name;
    int ID;
    int age;
  };
  struct Node {
    Student data;
    Node *next;
    Node *prev;
  };
  deque();

  // ~deque();
  void pushFront(Student newStudent);
  void pushBack(Student newStudent);
  void popFront();
  void popBack();
  Student peekFront();
  Student peekBack();
  void clear();
  void display();
  bool isEmpty();
  int count();

private:

  Node *front;
  Node *back;
};
