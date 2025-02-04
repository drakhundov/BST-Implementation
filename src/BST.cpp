#include "BST.h"

#include <iostream>

BST::BST() : root{nullptr} {}

BST::~BST() {
  if (root != nullptr) {
    destroy(root);
  }
}

void BST::destroy(BST_node *node) {
  if (node->left != nullptr) {
    destroy(node->left);
  }
  if (node->right != nullptr) {
    destroy(node->right);
  }
  delete node;
}

void BST::insert(int data) {
  if (root == nullptr) {
    root = new BST_node{data};
    return;
  }
  BST_node *cur, *parent;
  bool leftChild;
  cur = root;
  while (cur != nullptr) {
    if (data > cur->data) {
      parent = cur;
      cur = cur->right;
      leftChild = false;
    } else if (data < cur->data) {
      parent = cur;
      cur = cur->left;
      leftChild = true;
    } else if (data == cur->data) {
      // ! This condition should be kept
      // ! since cur is not nullptr.
      cur->cnt++;
      return;
    }
  }
  BST_node *insrt_node = new BST_node{data};
  if (leftChild) {
    parent->left = insrt_node;
  } else {
    parent->right = insrt_node;
  }
}

std::vector<BST_node *> BST::inorder_trav() const {
  std::vector<BST_node *> trav;
  inorder_trav(root, trav);
  return trav;
}

void BST::inorder_trav(BST_node *n, std::vector<BST_node *> &trav) const {
  if (n->left != nullptr) {
    inorder_trav(n->left, trav);
  }
  trav.push_back(n);
  if (n->right != nullptr) {
    inorder_trav(n->right, trav);
  }
}