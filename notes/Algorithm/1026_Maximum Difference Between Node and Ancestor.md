# 1026. Maximum Difference Between Node and Ancestor

## Description

> Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

> A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

## Solutions

### My Solution

_Brute Force_: for each node, find the maximum and minimum of its subtree.

```cpp
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDiffVal = 0;
vector<int> maxDiffSub(TreeNode* node) {
  if(node->left == nullptr && node->right == nullptr) {
    return vector<int>(2, node->val);
  } else {
    vector<int> minMax;
    int minVal, maxVal;
    if(node->left == nullptr) {
      minMax = maxDiffSub(node->right);
    } else if(node->right == nullptr) {
      minMax = maxDiffSub(node->left);
    } else {
      vector<int> leftMinMax = maxDiffSub(node->left);
      vector<int> rightMinMax = maxDiffSub(node->right);
      minMax.push_back(min(leftMinMax[0], rightMinMax[0]));
      minMax.push_back(max(leftMinMax[1], rightMinMax[1]));
    }
    minVal = minMax[0];
    maxVal = minMax[1];

    maxDiffVal = max(maxDiffVal, max(abs(node->val - minVal), abs(node->val - maxVal)));

    minMax[0] = min(node->val, minVal);
    minMax[1] = max(node->val, maxVal);

    return minMax;
  }
}

int maxAncestorDiff(TreeNode* root) {
  maxDiffSub(root);
  return maxDiffVal;
}
```

### Other Solutions

1. Recursion
   Instead of finding the maximum and minimum value of substrees for each node, this method finds the maximum and minimum value of parent nodes for each node.

```cpp
int maxDiffVal = 0;

void helper(TreeNode* node, int currMin, int currMax) {
  if(node != nullptr) {
    maxDiffVal = max(maxDiffVal, max(abs(node->val - currMin), abs(node->val - currMax)));
    currMin = min(currMin, node->val);
    currMax = max(currMax, node->val);
    helper(node->right, currMin, currMax);
    helper(node->left, currMin, currMax);
  }
  return;
}

int maxAncestorDiff(TreeNode* root) {
  helper(root, root->val, root->val);
  return maxDiffVal;
}

```
