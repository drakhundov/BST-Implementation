#include "BST.h"

BST_node::BST_node(int data) : data{data}, cnt{1} {}
BST_node::BST_node(int data, int cnt) : data{data}, cnt{cnt} {}