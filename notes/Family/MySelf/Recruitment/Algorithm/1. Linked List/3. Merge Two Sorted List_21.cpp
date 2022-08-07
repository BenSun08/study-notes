#include<iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

// Method1: two pointers
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *preHead = new ListNode(0);
  ListNode *p = preHead;
  
  while (list1 != nullptr && list2 != nullptr)
  {
    if(list2->val < list1->val) {
      p->next = list2;
      list2 = list2->next;
    } else {
      p->next = list1;
      list1 = list1->next;
    }
    p = p->next;
  }
  p->next = list1 == nullptr ? list2 : list1;

  return preHead->next;
}

// Method3: Recursion
ListNode* mergeTwoLists2(ListNode *list1, ListNode* list2) {
  if(list1 == nullptr) return list2;
  if(list2 == nullptr) return list1;

  if(list2->val < list1->val) {
    list2->next = mergeTwoLists2(list2->next, list1);
    return list2;
  } else {
    list1->next = mergeTwoLists2(list1->next, list2);
    return list1;
  }
}
 
int main() {
  int a1[] = { 1, 2, 4};
  int a2[] = { 1, 3, 4};

  ListNode *list1 = array2LinkedList(a1, 3);
  ListNode *list2 = array2LinkedList(a2, 3);

  ListNode *res = mergeTwoLists2(list1, list2);

  while (res != nullptr)
  {
    cout << res->val << endl;
    res = res->next;
  }
  
  return 0;
}