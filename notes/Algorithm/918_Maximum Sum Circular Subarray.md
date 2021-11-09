---
title: "918. Maximum Sum Circular Subarray"
author: "SanWang"
date: "2021-11-09"
---

# 918. Maximum Sum Circular Subarray

## Description

> Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

## Solutions

### My Solution

- this solution has exceeded time limit.

```cpp
 int maxSubarraySumCircular(vector<int>& nums) {
  int sz = nums.size();
  if (sz == 1) return nums[0];
  int maxVal = -30000;
  vector<int> sum(sz);
  sum[0] = nums[0];
  maxVal = max(maxVal, sum[0]);
  vector<int> rev(sz);
  rev[0] = nums[sz - 1];
  maxVal = max(maxVal, rev[0]);
  for (int i = 1; i < sz; i++) {
      sum[i] = sum[i - 1] + nums[i];
      rev[i] = rev[i - 1] + nums[sz - 1 - i];
      maxVal = max(maxVal, max(sum[i], rev[i]));
  }

  for (int j = 1; j < sz; j++) {
      for (int len = 1; len <= sz - 1; len++) {
          int remain = len >= sz - j ? 0 : rev[sz - 1 - j - len];
          int revSum = rev[sz - 1 - j] - remain;
          int ortSum = 0;
          int sumLen = len - (sz - j);
          if (sumLen > 0) ortSum += sum[sumLen - 1];
          maxVal = max(maxVal, revSum + ortSum);
      }
  }

  return maxVal;
}
```

### Others

1. case one: subarray take only the middle part of the array. This can be solved by [**Kadane's Algorithm**](./topics/Kadane's%20Algorithm.md)
2. case two: subarray take the tail and head of the array.

> in case two: we just need to calculate the max sum by: total sum minus minimum sum of subarray
> coner case: when all the elements are negative, case two need not to be considered.

```cpp
int maxSubarraySumCircular(vector<int>& nums) {
    int sum = 0;
    int localMax = 0;
    int localMin = 0;
    int globalMax = -30000;
    int globalMin = 30000;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        localMax = max(nums[i], localMax + nums[i]);
        localMin = min(nums[i], localMin + nums[i]);
        if (localMax > globalMax) globalMax = localMax;
        if (localMin < globalMin) globalMin = localMin;
    }
    if (globalMin != sum) globalMax = max(globalMax, sum - globalMin);

    return globalMax;
}
```
