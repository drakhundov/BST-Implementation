#include <iostream>
#include <vector>

#include "BST.h"

int main() {
  BST *bintree = new BST;
  bintree->insertRecur(10);
  bintree->insertRecur(12);
  bintree->insertRecur(1);
  bintree->insertRecur(0);
  bintree->insertRecur(5);
  std::vector<BST_node *> trav = bintree->inorderTrav();
  // int i;
  for (auto node : trav) {
    std::cout << node->data << " " << node->cnt << std::endl;
    // for (i = 0; i < node->cnt; i++) {
    //   std::cout << node->data << " ";
    // }
  }
  delete bintree;
  return 0;
}
