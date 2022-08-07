#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;
  Node(int x) {
    val = x;
    next = nullptr;
    random = nullptr;
  }
};

typedef unordered_map<Node*, Node*> nodeMap;
// Method 1: hash table + iteration
Node* copyRandomList(Node* head) {
  if(head == nullptr) return nullptr;

  Node *preHead = new Node(-1); 
  Node *orgCurr = head, *copyCurr = preHead;
  nodeMap map;

  while (orgCurr != nullptr)
  {
    if(map.find(orgCurr) == map.end()) {
      copyCurr->next = new Node(orgCurr->val);
      map.insert({ orgCurr, copyCurr->next });
    } else {
      copyCurr->next = map.find(orgCurr)->second;
    }
    copyCurr = copyCurr->next;

    if(orgCurr->random != nullptr) {
      if(map.find(orgCurr->random) == map.end()) {
        copyCurr->random = new Node(orgCurr->random->val);
        map.insert({ orgCurr->random, copyCurr->random });
      } else {
        copyCurr->random = map.find(orgCurr->random)->second;
      }
    }
    orgCurr = orgCurr->next;
  }
  
  return preHead->next;
}

// Method2: hash table + Recursion
nodeMap cachedNodes;
Node *copyRandomList2(Node *head) {
  if(head == nullptr) return nullptr;

  if(!cachedNodes.count(head)) {
    Node *headNew = new Node(head->val);
    cachedNodes[head] = headNew;  // the order is important, you must first insert the new mapped value into the hash table
    headNew->next = copyRandomList2(head->next);
    headNew->random = copyRandomList2(head->random);
  }

  return cachedNodes[head];
}

// Method 3: split the node and iterate it
Node *copyRandomList3(Node *head) {
  if(head == nullptr) return nullptr;
  Node *curr = head, *preHead = new Node(-1);
  Node *tmp, *copyCurr = preHead;
  while (curr != nullptr)
  {
    copyCurr->next = curr;
    tmp = curr->next;
    copyCurr = new Node(curr->val);
    curr->next = copyCurr;
    curr = tmp;
  }
  Node *res = preHead->next;
  preHead->next = nullptr;
  delete preHead;

  curr = head;
  while (curr != nullptr)
  {
    copyCurr = curr->next;
    copyCurr->random = curr->random == nullptr ? nullptr : curr->random->next;

    curr = copyCurr->next;
  }
  curr = head, copyCurr = curr->next; 
  res = copyCurr;
  while (copyCurr->next != nullptr)
  {
    curr->next = copyCurr->next;
    curr = curr->next;
    copyCurr->next = curr->next;
    copyCurr = copyCurr->next;
  }
  curr->next = nullptr;
  
  return res;
}

int main() {

  return 0;
}