#include <iostream>
using namespace std;
#define MAX 1000

template <class T>

class Stack {
    int top;

public:
    T a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(T x);
    T pop();
    T peek();
    int count();
    void display();
    bool isEmpty();
    bool isFull();
};
