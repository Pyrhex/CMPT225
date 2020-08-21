class AVL {
public:

  struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
  };

private:

  Node *root;
  void preOrder(Node *node);
  void postOrder(Node *node);
  void inOrder(Node *node);
  Node* insert(Node *node,
               int x);
  Node* find(Node *node,
             int x);

public:

  AVL();
  ~AVL();
  void insert(int x);
  Node* singleRightRotate(Node *& node);
  Node* singleLeftRotate(Node *& node);
  Node* doubleRightRotate(Node *& node);
  Node* doubleLeftRotate(Node *& node);
  Node* findMin(Node *node);
  Node* findMax(Node *node);
  int height(Node *node);
  int getBalance(Node *node);
  int childCount(Node *node);
  bool isRoot(Node *node);
  Node* getRoot();
  Node* find(int x);
  Node* parent(Node *node);
  Node* parent(Node *node,
               int x);


  void preOrder();
  void postOrder();
  void inOrder();
  void print(Node *node);
  int foo(Node *node);
};
