#include<iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(): val(0), next(NULL) {};
  ListNode(int x): val(x), next(NULL) {};
  ListNode(int x, ListNode *next): val(x), next(next) {};
};

ListNode *arr2List(int arr[], int len) {
  if(len == 0) return nullptr;

  ListNode *head = new ListNode(arr[0]);
  ListNode *p = head;
  for(int i = 1; i < len; i++) {
    p->next = new ListNode(arr[i]);
    p = p->next;
  }
  return head;
}

void printList(ListNode *head) {
  while (head != nullptr)
  {
    cout << head->val << endl;
    head = head->next;
  }
  
}

//  Method of Mine: tow pointers
ListNode* partition(ListNode* head, int x) {
  ListNode *headL = new ListNode(-1), *headG = new ListNode(-1, head);
  ListNode *pL = headL, **pG = &headG->next;
  while (*pG != nullptr)
  {
    if((*pG)->val < x) {
      pL->next = *pG;
      pL = pL->next;
      *pG = pL->next; 
    } else {
      pG = &(*pG)->next;
    }
  }
  pL->next = headG->next; 
  return headL->next;
}

// Method from Community
ListNode *partition2(ListNode* head, int x) {
  ListNode *headL = new ListNode(0), *headG = new ListNode(0);
  ListNode *pL = headL, *pG = headG;
  while (head != nullptr)
  {
    if(head->val < x) {
      pL->next = head;
      pL = pL->next;
    } else {
      pG->next = head;
      pG = pG->next;
    }
    head = head->next;
  }

  pG->next = nullptr; // ******very important, or it will end up with a circular linked list  

  pL->next = headG->next; 
  return headL->next;
}

int main() {
  int arr[] = { 1, 4, 3, 0, 2, 5, 2 };
  ListNode *head = arr2List(arr, 7);
  ListNode *res = partition2(head, 3);
  printList(res);

  return 0;
}