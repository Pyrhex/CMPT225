#include <iostream>
using namespace std;
class deque{
public:
  struct Student{
    int grade;
    int ID;
    int age;
  };
  struct Node{
    Student * data;
    Node * next;
    Node * prev;
  };
  Node * front;
  Node * back;
  // public:
    deque(){
      front = NULL;
      back = NULL;
    }
    // ~deque();
    void pushFront(Student * newStudent){
      Node * newNode = new Node;
      newNode->data = newStudent;
      newNode->prev = NULL;
      newNode->next = front;
      if(front != NULL){
        front->prev = newNode;
      }
      front = newNode;

    }    // void pushBack();
    Student * popFront(){
      Node * temp = new Node;
      temp = front;
      Student * data = front->data;
      front = front->next;
      front->prev = NULL;
      delete temp;
      return data;
    }
    // Student popBack();
    // Student peekFront();
    // Student peekBack();
    // void clear();

};
int main() {
  deque::Student bob;
  deque * test = new deque;
  test->pushFront(&bob);
  cout << test->popFront()->grade << endl;

}
