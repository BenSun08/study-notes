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

//  Method1: revers the sublist and concatenate them
ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode **preTail = &head;
  for(int i = 0; i < left - 1; i++) {
    preTail = &(*preTail)->next;
  }

  ListNode *subHead = *preTail, *curr = nullptr;
  ListNode *tmp, *subTail = subHead;
  for(int i = left; i < right; i++) {
    tmp = subHead->next;
    subHead->next = curr;
    curr = subHead;
    subHead = tmp;
  }
  tmp = subHead->next;
  subHead->next = curr;

  subTail->next = tmp;
  *preTail = subHead;
  return head;
}

//  Method 2: insertion
ListNode *reverseBetween2(ListNode *head, int left, int right) {
  ListNode **posToInsert = &head;
  for(int i = 0; i < left - 1; i++) {
    posToInsert = &(*posToInsert)->next;
  }

  ListNode *curr = (*posToInsert)->next;
  ListNode *subTail = *posToInsert;
  for(int j = left; j < right; j++) {
    subTail->next = curr->next; 
    curr->next = *posToInsert;
    *posToInsert = curr;
    curr = subTail->next;
  }
  return head;
}

int main() {
  
  return 0;
}