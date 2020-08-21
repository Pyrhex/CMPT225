#include <iostream>
#include "AVL.hpp"
using namespace std;
int main() {
  AVL *test = new AVL;

  test->insert(25);
  test->insert(20);
  test->insert(30);
  test->insert(35);
  test->insert(40);

  // test->insert(11);
  // test->insert(13);
  // test->insert(12);
  // test->insert(20);
  // test->insert(17);
  // test->insert(21);

  AVL::Node *root = test->getRoot();

  test->preOrder();

  // cout << "Min: "  << test->findMin(root)->data << endl;
  // cout << "Max: "  << test->findMax(root)->data << endl;
}
