---
title: "203. Remove Linked List Elements"
author: "SanWang"
date: "2021-10-20"
---

# 203. Remove Linked List Elements

## Description

> Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

## Solutions

### My Solution

```cpp
ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    while (head->val == val){
        ListNode* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) return head;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->val == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
```

### Other Solution

1. Pointer

```cpp
ListNode** list = &head;
  while (*list != nullptr)
  {
      if ((*list)->val == val) {
          *list = (*list)->next;
      }
      else {
          list = &(*list)->next;
      }
  }
  return head;
```

2. Recursion

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        removeHelper(head, val);
        return head;
    }
private:
    void removeHelper(ListNode*& curr, int& val) {
        if (curr != nullptr) {
            if (curr->val == val) {
                curr = curr->next;
                removeHelper(curr, val);
            }
            else {
                removeHelper(curr->next, val);
            }
        }
    }
};
```
