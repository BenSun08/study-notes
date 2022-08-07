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

ListNode *arr2ListCycle(int arr[], int len, int pos) {
  ListNode *preHead = new ListNode(0), *posPointer;
  ListNode *curr = preHead;
  pos = pos > -1 ? pos : len/2;
  for(int i = 0; i < pos; i++) {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }
  posPointer = curr;
  for(int j = pos; j < len; j++) {
    curr->next = new ListNode(arr[j]);
    curr = curr->next;
  }
  if(pos > -1) curr->next = posPointer->next;
  return preHead->next;
}

ListNode *detectCycle(ListNode *head) {
  ListNode *p1 = head, *p2 = head;        
  while (p1 !=nullptr && p2 != nullptr)
  {
    p1 = p1->next;
    p2 = p2->next;
    if(p2 == nullptr) return nullptr;
    else p2 = p2->next;

    if(p1 == p2) break;
  }
  if(p1 == nullptr || p2 == nullptr) return nullptr;
  p2 = head;
  while (p1 != p2)
  {
    p1 = p1->next;
    p2 = p2->next;
  }
  
  return p1;
}

int main() {
  int arr[] = { 3, 2, 0, 4 };
  ListNode *head = arr2ListCycle(arr, 4, 1);
  ListNode *res = detectCycle(head);

  if(res == nullptr) {
    cout << "no cycle" << endl;
  } else {
    int index = 0;
    ListNode *curr = head;
    while (curr != res)
    {
      curr = curr->next;
      index++;
    }
    cout << "tail connects to node index " << index << endl; 
  }

  return 0;
}