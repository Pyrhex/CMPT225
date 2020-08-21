#include <iostream>
#include <exception>
#include <assert.h>
#include "StackArray.hpp"
#define MAX 1000

using namespace std;

template<class T>
bool Stack<T>::push(T x) {
  try {
    if (top >= (MAX - 1)) { // if array is full
      throw std::overflow_error(
              "Stack Overflow Error: Item was not pushed onto the stack");
    }
    else {
      assert(top < MAX - 1); // array shouldn't be full in this block
      a[++top] = x;
      cout << x << " pushed into stack\n";
      return true;
    }
  }
  catch (const std::exception& e) { // catching overflow error
    cout << e.what() << endl; // displaying error to user
    return false;
  }
}

template<class T>
T Stack<T>::pop() {
  try {
    if (top < 0) { // if trying to remove from empty array
      throw std::underflow_error("Stack Underflow Error: No more items to pop");
    }
    else {
      assert(top >= 0);   // array should be non empty in this block
      int x = a[top--];
      return x;
    }
  }
  catch (const std::exception& e) { // catching underflow error
    cout << e.what() << endl;
    return -1;
  }
}

template<class T>
T Stack<T>::peek() {
  if (top < 0) {   // Checking if Stack is empty
    cout << "Stack is Empty";
    return 0;
  }
  else {
    assert(top >= 0);     // Stack is not empty
    int x = a[top];
    return x;
  }
}

template<class T>
int Stack<T>::count() {
  return top + 1;
}

template<class T>
void Stack<T>::display() {
  if (top < 0) { // checking if stack is empty
    cout << "Stack is Empty" << endl;
    return;
  }
  assert(top < 0); // Displaying if Stack is not Empty
  cout << "Stack: ";

  for (int i = 0; i <= top; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

template<class T>
bool Stack<T>::isEmpty() {
  return top < 0;
}

template<class T>
bool Stack<T>::isFull() {
  return top + 1 >= MAX;
}
