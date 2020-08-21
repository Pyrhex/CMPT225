#include <iostream>
#include "StackArray.cpp"

int main(){
  Stack<float> * test = new Stack<float>;
  test->push(3.1);
  test->push(2.2);
  test->pop();
  test->pop();
  test->pop();
  test->display();
  cout << "Count: " << test->count() << endl;
  cout << "Is it full? " << test->isFull() << endl;
  cout << "Is it empty? " << test->isEmpty() << endl;

}
