---
title: "114. Flatten Binary Tree to Linked List"
author: "SanWang"
date: "2021-10-25"
---

# 114. Flatten Binary Tree to Linked List

## Description

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

## Solution

### My Solution

1. Depth-First Search(stack)

```cpp
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* curr = new TreeNode();
    while (!s.empty())
    {
        curr->right = s.top();
        s.pop();
        curr = curr->right;
        if (curr->right != nullptr) {
            s.push(curr->right);
        }
        if (curr->left != nullptr) {
            s.push(curr->left);
            curr->left = nullptr;
        }
    }
}
```

2. DFS(Recursion)

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
private:
    TreeNode** helper(TreeNode* curr) {
        if (curr == nullptr) return nullptr;
        TreeNode** ptl = helper(curr->left);
        if (ptl) {
            *ptl = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        TreeNode** ptr = helper(curr->right);
        return ptr ? ptr : &curr->right;
    }
};
```

### The Other Solution

1. no stack and recursion.

```cpp
void flatten(TreeNode* root) {
    while (root)
    {
        if (root->left && root->right) {
            TreeNode* t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
 }
```

2. Recursion

use the similar principle with the solution above, though I don't think this solution is so 'recursive'.
