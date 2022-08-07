#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {};
  ListNode(int x): val(x), next(nullptr) {};
  ListNode(int x, ListNode *next): val(x), next(next) {};
  /* data */
};

// Method 1: Double pointer
ListNode* reverseLinkedList(ListNode *head) {
  if(head == nullptr) return nullptr;
  ListNode *temp = nullptr;
  ListNode *prev = nullptr;
  while (head != nullptr)
  {
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
};
ListNode* array2LinkedList(int arr[], int len) {
  if(len == 0) return nullptr;

  ListNode *head = new ListNode(arr[0]);
  ListNode *curr = head;
  for(int i = 1; i < len; i++) {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }
  return head;
};

// Method 2: Recursion 
ListNode* helper(int arr[], int len, int idx) {
  if(idx > len -1) return nullptr;
  else return new ListNode(arr[idx] ,helper(arr, len, idx + 1));
}
ListNode* array2LinkedList2(int arr[], int len) {
  if(len == 0) return nullptr;
  return new ListNode(arr[0], helper(arr, len, 1));
}
ListNode* reverseLinkedList2(ListNode *head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode* revHead = reverseLinkedList2(head->next);
  head->next->next = head;
  head->next = nullptr;
  return revHead;
}

int main () {
  int arr[] = { 1, 2, 3, 4, 5 };
  ListNode *head = array2LinkedList2(arr, 5);

  ListNode *reverseed = reverseLinkedList2(head);

  ListNode *curr = reverseed;
  while (curr != nullptr)
  {
    cout << curr->val << endl;
    curr = curr->next;
  }
  
  return 0;
};