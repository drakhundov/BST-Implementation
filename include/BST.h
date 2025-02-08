#ifndef BST_H
#define BST_H

#include <vector>

struct BST_node {
  int data, cnt;
  BST_node *left;
  BST_node *right;
  BST_node(int);
  BST_node(int, int);
};

class BST {
 public:
  BST();
  ~BST();
  BST_node *get_root() const;
  void insert(int);
  void insertRecur(int);                            // Recursive insertion.
  BST_node *find(int, BST_node * = nullptr) const;  // TODO
  std::vector<BST_node *> inorderTrav() const;

 private:
  BST_node *root;
  void destroy(BST_node *);
  void _inorderTravHelper(BST_node *, std::vector<BST_node *> &) const;
  BST_node *_insertRecurHelper(BST_node *, int);
};

#endif