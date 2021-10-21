#include<iostream>
#include<queue>
using namespace std;

// Binary Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//test example: 
// int arr[] = { 8,3,10,1,6, -1,14,-1,-1,4,7,13 };
// int arr[] = { 1, -1, 2, -1, 0, 3};
TreeNode* arr2BinaryTreeBF(int arr[], int len) {
    //int len = sizeof(arr) / sizeof(int);
    //int len = *(&arr + 1) - arr;
    if (len == 0) return new TreeNode();

    TreeNode* root = new TreeNode(arr[0]);
    if (len == 1) return root;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    TreeNode* curr;
    for (int i = 1; i < len; i += 2) {
        curr = nodeQueue.front();
        nodeQueue.pop();

        if (arr[i] != NULL) {
            TreeNode* left = new TreeNode(arr[i]);
            curr->left = left;
            nodeQueue.push(left);
        }
        if (i + 1 < len && arr[i + 1] != NULL) {
            TreeNode* right = new TreeNode(arr[i + 1]);
            curr->right = right;
            nodeQueue.push(right);
        }
    }
    return root;
}

// Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* array2LinkedList(int arr[], int len) {
    if (len == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < len; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}
// Linked Cycle List
ListNode* array2LinkedCycleList(int arr[], int len, int pos) {
    if (len == 0) return nullptr;
    vector<ListNode*> pts(len);
    ListNode* head = new ListNode(arr[0]);
    pts[0] = head;
    ListNode* curr = head;
    for (int i = 1; i < len; i++) {
        curr->next = new ListNode(arr[i]);
        pts[i] = curr->next;
        curr = curr->next;
    }
    if (pos > -1) pts[len - 1]->next = pts[pos];
    return head;
}