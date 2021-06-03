# 1818. Minimum Absolute Sum Difference

You are given two positive integer arrays nums1 and nums2, both of length n.

The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

## Related Topics

### Binary Search

To find a target value in a *sorted* list. **Or you can use it to find the closest value**.

```cpp
int binary_search(int arr[], int n, int T) {
 int L = 0; // the start
 int R = n - 1; // the end
 int M; // middle point 
 do{
  M = (L + R) / 2;
  cout << M << L << R << endl;
  if (T < arr[M]) {
   R = M -1;
  }
  else if (T > arr[M]) {
   L = M + 1;
  }
  else {
   return M;
  }
 } while (L <= R);
 return -1;
}
```

### Greedy Algorithm

Make the locally optimal choice at each stage.
[Greedy On Wiki](https://en.wikipedia.org/wiki/Greedy_algorithm)

## Solution

  1. loop on the `nums1`, find the optimal replacement for the element `nums1[i]`, which is closest to `nums2[i]`.
  2. to find the closet element, use *Binary Search*.
  3. How to get the minimal sum? Compare the currnet sum with the sum at the last loop, replace it if necessary.

```cpp
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int findClosest(vector<int>& sortedVec, int target) {
 int left = 0; // the start
 int end = sortedVec.size() - 1;
 int right = end; // the end
 int mid; // middle point 
 do {
  mid = (left + right) / 2;
  if (target < sortedVec[mid]) {
   right = mid - 1;
  }
  else if (target > sortedVec[mid]) {
   left = mid + 1;
  }
  else {
   return sortedVec[mid];
  }
 } while (left <= right);
 int val1 = sortedVec[mid];
 // my codes stuck here, caz in some test cases the value of mid+1 or mid-1 out of the range of the vector
 int index = target > val1 ? (mid + 1 > end ? end : mid + 1)  : (mid - 1 < 0 ? 0 : mid - 1);
 cout << "index: " << index << endl;
 int val2 = sortedVec[index];
 return abs(val1 - target) < abs(val2 - target) ? val1 : val2;
}

int minAbsSumDiff(vector<int>& nums1, vector<int>& nums2) {
 long long sum = 0;
 long long len = nums1.size();
 vector<int> sortedNums(nums1);

 sort(sortedNums.begin(), sortedNums.end());
 cout << "length:" << len << endl;
 for (int i = 0; i < len; i++) {
  sum += abs(nums1[i] - nums2[i]);
 }
 cout << "sum:" << sum << endl;

 long long res = sum;
 for (int i = 0; i < len; i++) {
  int closest = findClosest(sortedNums, nums2[i]);
  res = min(sum - abs(nums1[i] - nums2[i]) + abs(closest - nums2[i]), res);
 }
 return res % 1000000007;
}

int main() {
 int nums1[] = { 38, 48, 73, 55, 25, 47, 45, 62, 15, 34, 51, 20, 76, 78, 38, 91, 69, 69, 73, 38, 74, 75, 86, 63, 73, 12, 100, 59, 29, 28, 94, 43, 100, 2, 53, 31, 73, 82, 70, 94, 2, 38, 50, 67, 8, 40, 88, 87, 62, 90, 86, 33, 86, 26, 84, 52, 63, 80, 56, 56, 56, 47, 12, 50, 12, 59, 52, 7, 40, 16, 53, 61, 76, 22, 87, 75, 14, 63, 96, 56, 65, 16, 70, 83, 51, 44, 13, 14, 80, 28, 82, 2, 5, 57, 77, 64, 58, 85, 33, 24 };
 int nums2[] = { 90, 62, 8, 56, 33, 22, 9, 58, 29, 88, 10, 66, 48, 79, 44, 50, 71, 2, 3, 100, 88, 16, 24, 28, 50, 41, 65, 59, 83, 79, 80, 91, 1, 62, 13, 37, 86, 53, 43, 49, 17, 82, 27, 17, 10, 89, 40, 82, 41, 2, 48, 98, 16, 43, 62, 33, 72, 35, 10, 24, 80, 29, 49, 5, 14, 38, 30, 48, 93, 86, 62, 23, 17, 39, 40, 96, 10, 75, 6, 38, 1, 5, 54, 91, 29, 36, 62, 73, 51, 92, 89, 88, 74, 91, 87, 34, 49, 56, 33, 67 };

 int len = sizeof(nums1) / sizeof(nums1[0]);
 vector<int> v1, v2;
 for (int i = 0; i < len; i++) {
  v1.push_back(nums1[i]);
  v2.push_back(nums2[i]);
 }
 cout << "Minimun Absolute Sum Difference: " << minAbsSumDiff(v1, v2) << endl;

 return 0;
}
```
