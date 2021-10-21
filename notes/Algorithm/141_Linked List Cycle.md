---
title: "141. Linked List Cycle"
author: "SanWang"
date: "2021-10-21"
---

# 141. Linked List Cycle

## Description

> Given head, the head of a linked list, determine if the linked list has a cycle in it.
> There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
> Return true if there is a cycle in the linked list. Otherwise, return false.

## Solutions

### My Solution

```cpp
bool hasCycle(ListNode* head) {
    unordered_map<ListNode*, bool> ptMap;
    ListNode* curr = head;
    while (curr != nullptr)
    {
        if (ptMap.find(curr) != ptMap.end()) return true;
        else ptMap[curr] = true;
        curr = curr->next;
    }
    return false;
}
```

### Other Solution

1. Two pointers

```cpp
bool hasCycle(ListNode* head) {
    ListNode* walker = head;
    ListNode* runner = head;
    while (runner!= nullptr && runner->next != nullptr)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner) return true;
    }
    return false;
}
```
