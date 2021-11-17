---
title: "430. Flatten a Multilevel Doubly Linked List"
author: "SanWang"
date: "2021-11-11"
---

# 430. Flatten a Multilevel Doubly Linked List

## Description

> You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

## Solutions

### My Solution

- use stack to store the `curr->next`

```cpp
DoublyListNode* flatten(DoublyListNode* head) {
    DoublyListNode* prev = new DoublyListNode();
    prev->next = head;
    DoublyListNode* curr = head;
    stack<DoublyListNode*> s;

    while (curr) {
        if (curr->child) {
            if(curr->next) s.push(curr->next);
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = nullptr;
        }
        prev = prev->next;
        curr = curr->next;
    }

    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        prev->next = curr;
        curr->prev = prev;
        while (curr)
        {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return head;
}
```

### Other Solutions

1. Dynamic Programming

```cpp
DoublyListNode* flatten(DoublyListNode* head) {
    for (DoublyListNode* curr = head; curr; curr = curr->next) {
        if (curr->child) {
            DoublyListNode* tail = curr->next;
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = nullptr;

            if (tail) {
                DoublyListNode* temp = curr->next;
                while (temp->next) temp = temp->next;
                temp->next = tail;
                tail->prev = temp;
            }
        }
    }
    return head;
}
```

2. Recursion

```cpp
void helper(DoublyListNode* node) {
    if (!node) return;
    if (node->child) {
        DoublyListNode* temp = node->next;
        node->next = node->child;
        node->next->prev = node;
        node->child = nullptr;
        if (temp) {
            DoublyListNode* walker = node->next;
            while (walker->next) walker = walker->next;
            walker->next = temp;
            temp->prev = walker;
        }
    }
    helper(node->next);
}
DoublyListNode* flatten(DoublyListNode* head) {
    helper(head);
    return head;
}
```
