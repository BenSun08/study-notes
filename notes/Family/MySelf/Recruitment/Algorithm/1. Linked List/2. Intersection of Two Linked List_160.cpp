#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Method1: Hash Table
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if(headA == nullptr || headB == nullptr) return nullptr;

  ListNode* pA = headA;
  unordered_set<ListNode*> visited;
  while (pA != nullptr)
  {
    visited.insert(pA);
    pA = pA->next; 
  }
  
  ListNode* pB = headB;
  while (pB != nullptr)
  {
    if(visited.find(pB) != visited.end()) return pB;
    pB = pB->next;
  }
  
  return nullptr;
}

// Method2: Two pointers
// of Mine
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
  if(headA == nullptr || headB == nullptr) return nullptr;

  ListNode *pA = headA, *pB = headB;
  for(int i = 0; i < 3; i++) {
    if(pA == nullptr) {
      pA = headB;
    } else if(pB == nullptr) {
      pB = headA;
    }

    while (pA != nullptr && pB != nullptr)
    {
      if(pA == pB) return pA;
      pA = pA->next;
      pB = pB->next;
    }
  }

  return nullptr;
}

// Two pointers from community
ListNode* getIntersectionNode3(ListNode *headA, ListNode *headB) {
  if(headA == nullptr || headB == nullptr) return nullptr;

  ListNode *pA = headA, *pB = headB;
  while (pA != pB)
  {
    pA = pA == nullptr ? headB : pA->next;
    pB = pB == nullptr ? headA : pB->next;
  }
  return pA; 
}

int main() {

  return 0;
}