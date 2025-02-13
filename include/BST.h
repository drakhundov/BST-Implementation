#ifndef BST_H
#define BST_H

#include <vector>

struct BST_node {
  int data, cnt;
  BST_node *left;
  BST_node *right;
  BST_node *parent;
  BST_node(int data);
  BST_node(int data, int cnt);
};

class BST {
 public:
  BST();
  ~BST();
  BST_node *get_root() const;
  // * `remove` and `insert` might use
  // * both recursive and pointer-based
  // * methods depending on the height.
  void insert(int data);
  BST_node *find(int data, BST_node *node = nullptr) const;
  void remove(int item);
  void inorderTrav(std::vector<BST_node *> &trav) const;
  void preorderTrav(std::vector<BST_node *> &trav) const;
  void postorderTrav(std::vector<BST_node *> &trav) const;
  BST_node *findMin(BST_node *node) const;
  BST_node *findMax(BST_node *node) const;
  int height() const;

 private:
  BST_node *root;
  void destroy(BST_node *node);
  void insertPtrMethod(int data);
  BST_node *insertRecurMethod(BST_node *node, int data);
  void removePtrMethod(BST_node *node, int item);
  BST_node *removeRecurMethod(BST_node *node, int item);
  void inorderTrav(std::vector<BST_node *> &trav, BST_node *node) const;
  void preorderTrav(std::vector<BST_node *> &trav, BST_node *node) const;
  void postorderTrav(std::vector<BST_node *> &trav, BST_node *node) const;
  int height(BST_node *node) const;
};

#endif