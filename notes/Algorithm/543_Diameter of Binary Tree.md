# 543. Diameter of Binary Tree

> Given the root of a binary tree, return the length of the **diameter** of the tree.
> The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree.
> This path may or may not pass through the root.
> The **length** of a path between two nodes is represented by the number of edges between them.

## Solutions

### My first solution

  calculate each node's left subtree's depth and right subtree's depth, so the longest distance pass by this node is `leftDepth + 1 + rightDepth + 1`

```cpp
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
 int val;
 TreeNode* left;
 TreeNode* right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int calcDepth(TreeNode* node) {
 queue<TreeNode*> qe;
 TreeNode* temp;
 qe.push(node);
 node->val = 0;
 int tempVal, maxDep = 0;
 while (qe.size() > 0) {
  temp = qe.front();
  qe.pop();
  tempVal = temp->val;
  maxDep = max(tempVal, maxDep);
  if (temp->right || temp->left) {
   if (temp->left) {
    temp->left->val = tempVal + 1;
    qe.push(temp->left);
   }
   if (temp->right) {
    temp->right->val = tempVal + 1;
    qe.push(temp->right);
   }
  }
 }
 return maxDep;
}

int diameterOfBinaryTree(TreeNode* root) {
 queue<TreeNode*> qe;
 TreeNode* temp;
 qe.push(root);
 int leftDep = 0, rightDep = 0, maxHeight = 0, height = 0;
 while (qe.size() > 0) {
  temp = qe.front();
  qe.pop();
  leftDep = 0;
  rightDep = 0;
  if (temp->left) {
   qe.push(temp->left);
   leftDep = calcDepth(temp->left) + 1;
  }
  if (temp->right) {
   qe.push(temp->right);
   rightDep = calcDepth(temp->right) + 1;
  }
  height = leftDep + rightDep;
  maxHeight = max(height, maxHeight);
 }
 return maxHeight;
}
```

  However, each node will be travesed multiple time, cosuming a lot more time. And also, each node's value is changed.

### Solution using recursion

```cpp
int calcDepth(TreeNode* node) {
 if (node == NULL) {
  return 0;
 }
 return 1 + max(calcDepth(node->left), calcDepth(node->right));
}

int diameterOfBinaryTree(TreeNode* root) {
 if (root == NULL) {
  return 0;
 }
 int currHeight, leftHeight, rightHeight;
 currHeight = calcDepth(root->left) + calcDepth(root->right);
 leftHeight = diameterOfBinaryTree(root->left);
 rightHeight = diameterOfBinaryTree(root->right);

 return max({ currHeight, leftHeight, rightHeight });
}
```

### Recursive solution without calculating height of node repeatedly

```cpp
int maxHeight = 0;
int calcDepth(TreeNode* node) {
 if (node == NULL) {
  return 0;
 }
 int leftDepth, rightDepth;
 leftDepth = calcDepth(node->left);
 rightDepth = calcDepth(node->right);
 maxHeight = max(maxHeight, leftDepth + rightDepth);

 return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(TreeNode* root) {
 calcDepth(root);
 return maxHeight;
}
```
