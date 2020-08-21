#include <iostream>
#include "AVL.hpp"
using namespace std;


AVL::AVL() {
  root = NULL;
}

AVL::~AVL() {
  root = NULL;
}

int max(int x, int y) {
  if (x > y) {
    return x;
  }
  else {
    return y;
  }
}

int AVL::height(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

int AVL::getBalance(Node *node) {
  if (node == NULL) {
    return 0;
  }
  int balance = height(node->left) - height(node->right);

  return balance;
}

AVL::Node * AVL::getRoot() {
  cout << "Root: " << root->data << endl;
  return root;
}

AVL::Node * AVL::find(int x) {
  if (root->data == x) {
    cout << "No parent to the root" << endl;
    exit(1);
    return NULL;
  }

  if (root->data < x) {
    return find(root->right, x);
  }
  else {
    return find(root->left, x);
  }
}

AVL::Node * AVL::find(Node *node, int x) {
  if (node->data == x) {
    return node;
  }

  if (node->data < x) {
    return find(node->right, x);
  }
  else {
    return find(node->left, x);
  }
}

AVL::Node * AVL::parent(Node *node) {
  int x = node->data;

  if (root->data == x) {
    cout << "No parent to the root" << endl;
    exit(1);
    return NULL;
  }

  if ((root->right->data == x) || (root->left->data == x)) {
    return root;
  }

  if (root->data < x) {
    return parent(root->right, x);
  }
  else {
    return parent(root->left, x);
  }
}

AVL::Node * AVL::parent(Node *node, int x) {
  if ((node->left->data == x) || (node->right->data == x)) {
    return node;
  }

  if (node->data < x) {
    return parent(node->right, x);
  }
  else {
    return parent(node->left, x);
  }
}

int AVL::childCount(AVL::Node *node) {
  if ((node->left  != NULL) && (node->right != NULL)) {
    return 2;
  }
  else if ((node->left == NULL) && (node->right == NULL)) {
    return 0;
  }
  else {
    return 1;
  }
}

AVL::Node * AVL::findMin(Node *node) {
  if (node->left == NULL) {
    return node;
  }
  return findMin(node->left);
}

AVL::Node * AVL::findMax(Node *node) {
  if (node->right == NULL) {
    return node;
  }
  return findMax(node->right);
}

void AVL::insert(int x) {
  root = insert(root, x);
}

AVL::Node * AVL::insert(Node *node, int x) {
  if (node == NULL)
  {
    node = new Node;
    node->data = x;
    node->left = NULL;
    node->right = NULL;
  }
  else if (x < node->data) {
    node->left = insert(node->left, x);

    if (getBalance(node) == 2) {
      if (x < node->left->data) {
        node = singleRightRotate(node);
      }
      else {
        node = doubleRightRotate(node);
      }
    }
  }
  else if (x > node->data) {
    node->right = insert(node->right, x);

    if (getBalance(node) == -2) {
      if (x > node->right->data) {
        node = singleLeftRotate(node);
      }
      else {
        node = doubleLeftRotate(node);
      }
    }
  }
  node->height = 1 + max(height(node->left), height(node->right));

  return node;
}

AVL::Node * AVL::singleRightRotate(Node *& node) {
  cout << "Single Rotate Right" << endl;
  Node *temp = node->left;

  node->left = temp->right;
  temp->right = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  temp->height = max(height(temp->left), node->height) + 1;
  return temp;
}

AVL::Node * AVL::singleLeftRotate(Node *& node) {
  cout << "Single Rotate Left" << endl;
  Node *temp = node->right;
  Node *temp2 = temp->left;

  temp->left = node;
  node->right = temp2;

  node->height = max(height(node->left), height(node->right)) + 1;
  temp->height = max(height(temp->left), height(temp->right)) + 1;
  return temp;
}

AVL::Node * AVL::doubleRightRotate(Node *& node) {
  return NULL;
}

AVL::Node * AVL::doubleLeftRotate(Node *& node) {
  return NULL;
}

void AVL::preOrder() {
  preOrder(root);
}

void AVL::postOrder() {
  postOrder(root);
}

void AVL::inOrder() {
  inOrder(root);
}

bool AVL::isRoot(Node *node) {
  if (node == root) {
    return true;
  }
  return false;
}

void AVL::preOrder(Node *node) {
  if (node == NULL) {
    return;
  }
  cout << node->data << " ";
  preOrder(node->left);
  preOrder(node->right);
}

void AVL::postOrder(Node *node) {
  if (node == NULL) {
    return;
  }
  postOrder(node->left);
  postOrder(node->right);
  cout << node->data << " ";
}

void AVL::inOrder(Node *node) {
  if (node == NULL) {
    return;
  }
  inOrder(node->left);
  cout << node->data << " ";
  inOrder(node->right);
}

void AVL::print(Node *node) {
  cout << node->data << endl;
  print(node->right);
  print(node->left);
}

// bool AVL::isAVL() {}
