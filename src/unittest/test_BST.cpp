#include <gtest/gtest.h>

#include "BST.h"

// Test fixture for BST
class BSTTest : public ::testing::Test {
 protected:
  BST bst;

  void SetUp() override {
    // Initialize the BST with some values
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
  }
};

// Test insertion
TEST_F(BSTTest, Insert) {
  std::vector<BST_node*> inorder;
  bst.inorderTrav(inorder);
  std::vector<int> expected = {3, 5, 7, 10, 12, 15, 18};
  std::vector<int> result;
  for (auto node : inorder) {
    result.push_back(node->data);
  }
  EXPECT_EQ(result, expected);
}

// Test find
TEST_F(BSTTest, Find) {
  BST_node* node = bst.find(7);
  ASSERT_NE(node, nullptr);
  EXPECT_EQ(node->data, 7);

  node = bst.find(20);
  EXPECT_EQ(node, nullptr);
}

// Test remove
TEST_F(BSTTest, Remove) {
  bst.remove(10);
  std::vector<BST_node*> inorder;
  bst.inorderTrav(inorder);
  std::vector<int> expected = {3, 5, 7, 12, 15, 18};
  std::vector<int> result;
  for (auto node : inorder) {
    result.push_back(node->data);
  }
  EXPECT_EQ(result, expected);
}

// Test inorder traversal
TEST_F(BSTTest, InorderTraversal) {
  std::vector<BST_node*> inorder;
  bst.inorderTrav(inorder);
  std::vector<int> expected = {3, 5, 7, 10, 12, 15, 18};
  std::vector<int> result;
  for (auto node : inorder) {
    result.push_back(node->data);
  }
  EXPECT_EQ(result, expected);
}

// Test preorder traversal
TEST_F(BSTTest, PreorderTraversal) {
  std::vector<BST_node*> preorder;
  bst.preorderTrav(preorder);
  std::vector<int> expected = {10, 5, 3, 7, 15, 12, 18};
  std::vector<int> result;
  for (auto node : preorder) {
    result.push_back(node->data);
  }
  EXPECT_EQ(result, expected);
}

// Test postorder traversal
TEST_F(BSTTest, PostorderTraversal) {
  std::vector<BST_node*> postorder;
  bst.postorderTrav(postorder);
  std::vector<int> expected = {3, 7, 5, 12, 18, 15, 10};
  std::vector<int> result;
  for (auto node : postorder) {
    result.push_back(node->data);
  }
  EXPECT_EQ(result, expected);
}

// Test height
TEST_F(BSTTest, Height) { EXPECT_EQ(bst.height(), 3); }

// Test findMin
TEST_F(BSTTest, FindMin) {
  BST_node* minNode = bst.findMin(bst.get_root());
  ASSERT_NE(minNode, nullptr);
  EXPECT_EQ(minNode->data, 3);
}

// Test findMax
TEST_F(BSTTest, FindMax) {
  BST_node* maxNode = bst.findMax(bst.get_root());
  ASSERT_NE(maxNode, nullptr);
  EXPECT_EQ(maxNode->data, 18);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}