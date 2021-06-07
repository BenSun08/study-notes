# 160. Intersection of Two Linked Lists

> Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the
> two linked lists have no intersection at all, return null.
> It is guaranteed that there are no cycles anywhere in the entire linked structure.
> Note that the linked lists must retain their original structure after the function returns.

## Solutions

1. Brute Force
2. Hash Table
  let List B transform into a hash table, let the time consumption transform into memory storage.
3. Two Pointers.he
   Assumed that list A has length `M`, list B has length `N`. Since when they intersect, they will share the same 'tail', we can traverse the longer list from `|M - N|` position.

```cpp
 int shortLen = 0, diff = 0;
 ListNode* trackerA = headA, * trackerB = headB;
 while (trackerA && trackerB)
 {
  shortLen++;
  trackerA = trackerA->next;
  trackerB = trackerB->next;
 }
 ListNode* restTracker = trackerA ? trackerA : trackerB;
 ListNode* longList = trackerA ? headA : headB;
 ListNode* shortList = trackerA ? headB : headA;
 while (restTracker)
 {
  diff++;
  restTracker = restTracker->next;
 }
 while (diff > 0) {
  longList = longList->next;
  diff--;
 }
 while (longList) {
  if (longList == shortList) {
   return longList;
  }
  else {
   longList = longList->next;
   shortList = shortList->next;
  }
 }
 return NULL;
```
