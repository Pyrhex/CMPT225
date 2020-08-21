#include <iostream>
#include "deque.hpp"
using namespace std;

int main() {
  deque::Student bob = { "Bob", 1, 10 };
  deque::Student diana = { "Diana", 2, 23 };
  deque::Student brian = { "Brian", 3, 21 };
  deque::Student kevin = { "Kevin", 4, 50 };
  deque *test = new deque;

  test->pushFront(bob);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->pushBack(diana);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->pushBack(brian);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->popFront();
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->pushFront(kevin);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->pushBack(bob);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->popBack();
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  test->pushFront(kevin);
  cout << "Front: " << test->peekFront().name;
  cout << " Back: " << test->peekBack().name << endl;
  test->display();
  cout << "Is it empty? " <<  test->isEmpty() << endl;
  test->clear();
  cout << "Count: " << test->count() << endl;
  cout << "Is it empty? " <<  test->isEmpty() << endl;
  test->display();
}
