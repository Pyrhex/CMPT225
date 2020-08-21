#include <iostream>
#include <exception>
#include "deque.hpp"
using namespace std;

deque::deque() {
  front = NULL;
  back  = NULL;
}

void deque::pushFront(Student newStudent) {
  Node *newNode = new Node; // creating new Node

  newNode->data = newStudent; // copying data from parameter into newNode
  newNode->prev = NULL; // newNode is front so prev = NULL
  newNode->next = front; // newNode is front so next = front

  if (front != NULL) {
    front->prev = newNode; // setting previous of the original front to the new
                           // node
  }
  front = newNode; // updating front of deque

  if (back == NULL) {
    back = newNode; // updating back if deque was originally empty
  }
  cout << "Pushing " << newStudent.name << " into front of deque" << endl;
}

void deque::pushBack(Student newStudent) {
  Node *newNode = new Node;  // creating new Node

  newNode->data = newStudent; // copying data from parameter into newNode
  newNode->next = NULL; // newNode is at the back so the next is NULL;
  newNode->prev = back; // newNode is at the back so the prev = back;

  if (back != NULL) {
    back->next = newNode; // setting next of the original back to the new
                          // node
  }
  back = newNode; // updating the new back

  if (front == NULL) {
    front = newNode; // if empty the front is the newNode
  }
  cout << "Pushing " << newStudent.name << " into back of deque" << endl;
}

void deque::popFront() {
  try {
    if (front == NULL) {
      throw std::underflow_error("Deque Underflow Error: No more items to pop");
    }
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
    exit(0);
  }
  Node *temp = new Node;

  temp = front;
  cout << "Popping " << temp->data.name << " from front of deque" << endl;
  front = front->next;

  if (front != NULL) {
    front->prev = NULL;
  }
  delete temp;
}

void deque::popBack() {
  try {
    if (front == NULL) {
      throw std::underflow_error("Deque Underflow Error: No more items to pop");
    }
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
    exit(0);
  }
  Node *temp = new Node;

  temp = back;
  cout << "Popping " << temp->data.name << " from back of deque" << endl;
  back = back->prev;

  if (back != NULL) {
    back->next = NULL;
  }
  delete temp;
}

deque::Student deque::peekFront() {
  try {
    if (front != NULL) {
      return front->data; // return the front if not empty
    }
    throw std::underflow_error("There is nothing in the deque");
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
    exit(0);
  }
}

//
deque::Student deque::peekBack() {
  try {
    if (back != NULL) {
      return back->data; // return the back if not empty
    }
    throw std::underflow_error("There is nothing in the deque");
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
    exit(0);
  }
}

void deque::clear() {
  Node *temp = new Node;

  while (front != NULL) {
    temp  = front;
    front = front->next;
    delete temp;
  }
  front = NULL;
  back  = NULL;
}

void deque::display() {
  if (count() == 0) {
    cout << "Deque is empty" << endl;
  }
  Node *temp = new Node;

  temp = front;

  while (temp != NULL) { // traversing the deque
    cout << "Name: " << temp->data.name << " -> ";
    temp = temp->next;
  }
  cout << endl;
}

bool deque::isEmpty() {
  if (count() == 0) {
    return true;
  }
  return false;
}

int deque::count() {
  if ((front == NULL) && (back == NULL)) {
    return 0;
  } // if the front and back are NULL then it is empty
  int   count = 0;
  Node *temp  = new Node;

  temp = front;

  while (temp != NULL) { // traversing the deque
    count++;
    temp = temp->next;
  }
  return count;
}
