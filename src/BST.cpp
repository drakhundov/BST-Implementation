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

void BST::insertRecur(int data) { root = BST::_insertRecurHelper(root, data); }

BST_node *BST::_insertRecurHelper(BST_node *node, int data) {
  if (node == nullptr) {
    return new BST_node{data};
  }
  if (data > node->data) {
    node->right = _insertRecurHelper(node->right, data);
  } else if (data < node->data) {
    node->left = _insertRecurHelper(node->left, data);
  } else {
    //! data == node->data
    node->cnt++;
  }
  return node;
}

BST_node *BST::find(int item, BST_node *refNode) const {
  if (refNode == nullptr) {  // Default value.
    refNode = root;
  }
  if (item > refNode->data) {
    return find(item, refNode->right);
  } else if (item < refNode->data) {
    return find(item, refNode->left);
  } else {
    return refNode;
  }
}

std::vector<BST_node *> BST::inorderTrav() const {
  std::vector<BST_node *> trav;
  _inorderTravHelper(root, trav);
  return trav;
}

void BST::_inorderTravHelper(BST_node *n, std::vector<BST_node *> &trav) const {
  if (n->left != nullptr) {
    _inorderTravHelper(n->left, trav);
  }
  trav.push_back(n);
  if (n->right != nullptr) {
    _inorderTravHelper(n->right, trav);
  }
}