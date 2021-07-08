# 402. Remove K Digits

## Description

> Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

## Solutions

### My Solution

My idea:
The core to solve the problem is remove the leftmost greater degits, that is, to find the position of the next less number for every digit. And then remove the digits from it till that digit if the distance between is less than k.

- using the data structure *Monotonic Stack* to store the position, keeping its corresponind value in ascending order.
- loop from the end of `num`, if the top of stack is greater than or equal to current digit, pop it while stack is not empty.
- record the position of the less number for each digit.
- remove from the left according to the distance. Supposed `m` digits have removed, and `k > m`, that means the result `string` is in ascending order. Then remove `k - m` digits from rightmost of the `string`.
- remove leading `'0'`s.

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

string removeKdigits(string num, int k) {
 vector<int> pos(num.size(), -1);
 vector<bool> pos2Rm(num.size(), false);
 stack<int> s;
 for (int i = num.size() - 1; i >= 0; i--) {
  while (!s.empty() && num[i] <= num[s.top()])
  {
   s.pop();
  }
  if (!s.empty()) {
   pos[i] = s.top();
  }
  s.push(i);
 }

 int j = 0;
 while (j < num.size() && k >= 0) {
  if (pos[j] == -1) {
   j++;
   continue;
  }
  int dis = pos[j] - j;
  if (dis <= k) {
   for (int m = j; m < pos[j]; m++) {
    pos2Rm[m] = true;
   }
   k -= dis;
   j = pos[j];
  }
  else {
   j++;
  }
 }

 string res;
 for (int n = 0; n < num.size(); n++) {
  if (!pos2Rm[n]) res.push_back(num[n]);
 }
 if (k > 0) res = res.substr(0, res.size() - k);
 int leadingZero = 0;
 for (int i = 0; i < res.size(); i++) {
  if (res[i] == '0') leadingZero++;
  else break;
 }
 if (leadingZero > 0) res = res.substr(leadingZero, res.size() - leadingZero);
 if (res == "") res.push_back('0');

 return res;
}

int main() {
 string input = "1173";
 string output = removeKdigits(input, 2);
 
 cout << "The smallest number is:" << output << endl;

 return 0;
}
```

### Other Solutions

Idea: remove all *peak values*(values whose right value is less) from left to right.

```cpp
string removeKdigits(string num, int k) {
 string res;
 for (int i = 0; i < num.size() && k >= 0; i++) {
  while (!res.empty() && num[i] < res.back() && k > 0) {
   res.pop_back();
   k--;
  }
  res.push_back(num[i]);
 }
 if(k > 0) res.erase(res.size() - k, k);

 int leadingZeroNum = 0;
 for (int j = 0; j < res.size(); j++) {
  if (res[j] == '0') leadingZeroNum++;
  else break;
 }
 res.erase(0, leadingZeroNum);

 return res.size() == 0 ? "0" : res;
}
```
