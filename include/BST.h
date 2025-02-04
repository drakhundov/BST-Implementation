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
  std::vector<BST_node *> inorder_trav() const;

 private:
  BST_node *root;
  void destroy(BST_node *);
  void inorder_trav(BST_node *, std::vector<BST_node *> &) const;
};

#endif