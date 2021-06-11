# 1331. Rank Transform of an Array

## Description

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

- Rank is an integer starting from 1.
- The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
- Rank should be as small as possible.

## Solution

### My Solution

- sort the array.
- use an array to storage the ranking of the value.
- loop over the unsorted array, use *Binary Search* to find the ranking of the value through the sorted array.

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int T) {
 int L = 0, R = arr.size() - 1;
 int M, midVal;
 do
 {
  M = (R + L) / 2;
  midVal = arr[M];
  if (T < midVal) {
   R = M - 1;
  }
  else if (T > midVal) {
   L = M + 1;
  }
  else {
   return M;
  }
 } while (L <= R);
 return M;
}

vector<int> arrayRankTransform(vector<int>& arr) {
 vector<int> sortedArr(arr);
 vector<int> rankArr(arr.size(), 1);
 sort(sortedArr.begin(), sortedArr.end());

 for (int i = 0; i < arr.size(); i++) {
  if (i > 0) {
   rankArr[i] = sortedArr[i] == sortedArr[i - 1] ? rankArr[i - 1] : rankArr[i - 1] + 1;
  }
  arr[i] = binarySearch(sortedArr, arr[i]);
 }
 for (int j = 0; j < arr.size(); j++) {
  arr[j] = rankArr[arr[j]];
 }
 return arr;
}

int main() {
 int arr[] = { 37,12,28,9,100,56,80,5,12 };
 vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

 vector<int> rankedArr = arrayRankTransform(nums);
 cout << "The ranked array is:" << endl;
 for (int i = 0; i < rankedArr.size(); i++) {
  cout << rankedArr[i] << "  ";
 }

 return 0;
}
```

### Solution using map

- `map` in C++ is sorted. (`map` is implemented as *binary search tree* in C++).
- `map` has no duplicated keys, is consistent with the problems that same equal values have the same rank.

```cpp
vector<int> arrayRankTransform(vector<int>& arr) {
 map<int, int> valRankMap;
 for (int val : arr) {
  valRankMap[val] = 0;
 }
 int pos = 0;
 for (map<int, int>::iterator it = valRankMap.begin(); it != valRankMap.end(); it++) {
  it->second = ++pos;
 }
 for (int i = 0; i < arr.size(); i++) {
  arr[i] = valRankMap[arr[i]];
 }
 return arr;
}
```

### Solution using set

- `set` in C++ is sorted.
- duplicated value in a set will be omitted.

```cpp
vector<int> arrayRankTransform(vector<int>& arr) {
 set<int> valSet(arr.begin(), arr.end());
 vector<int> setVec;
 for (int s : valSet) {
  setVec.push_back(s);
 }
 for (int i = 0; i < arr.size(); i++) {
  int dist = lower_bound(setVec.begin(), setVec.end(), arr[i]) - setVec.begin();
  arr[i] = dist + 1;
 }
 return arr;
}
```
