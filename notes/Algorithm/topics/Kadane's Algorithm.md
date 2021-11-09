---
title: "Kadane's Algorithm"
author: "SanWang"
date: "2021-11-08"
---
# Kadane's Algorithm

> The algorithm to solve the *maximum sum subarray problem*.

## Implementation

```cpp
int findMaxSumSubarr(vector<int>& nums) {
  int local_max = 0;
  int global_max = -INFINITY;
  for(int i = 0; i < nums.size(); i++) {
    local_max = max(nums[i], local_max + nums[i]);
    if(local_max > global_max) {
      global_max = local_max;
    }
  }
  return global_max;
}
```

## Proctices

> Find The Maximum Sum Subarray of a Circular Array. [918.](../918_Maximum%20Sum%20Circular%20Subarray.md)
