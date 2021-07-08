# Monotonic Stack

**Monotonic Stack** is stack that always keep ascending/descending order under some mechanisms.

## Application

### The Next Greater/Less Number

given a array, return an array of the greater number of every element

```cpp
vector<int> theGreaterNum(vector<int> &nums) {
  vector<int> res(nums.size(), -1);
  stack<int> s;
  for(int i = nums.size() - 1; i >=0; i--) {
    while(!s.empty() && s.top() < nums[i]) {
      s.pop();
    }
    if(!s.empty()) res[i] = s.top();
    s.push(nums[i]);
  }
  return res;
}
```

### 402. Remove K digits(LeetCode)
