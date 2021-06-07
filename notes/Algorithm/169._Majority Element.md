# 169. Majority Element

> Given an array nums of size n, return the majority element.
> The majority element is the element that appears more than ⌊n / 2⌋ times. You may
> assume that the majority element always exists in the array.

## Related Topic

### Boyer-Moore Majority Vore Algorithm

pseudo code:

- Initialize `m` to record the candidate and `i = 0` to count.
- For sequence number `x`:
  - if `i == 0`, let `m = x`;
  - if `m == x`, `i++`;
  - else `i--`;
- return `m`.

## Solution

```cpp
#include<iostream>
#include<vector>

int findMajority(vector<int> &nums) {
  int candidate, count = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(count == 0) {
      candidate = nums[i]
    }
    if(candidate == nums[i]) {
      count++;
    }
    else {
      count--;
    }
  }
  return candidate;
}
```
