# Binary Search

## Normal

## Duplicated Elements

### Procedure for finding the leftmost element

- The difference lies on: when the middle value equal to target, do not return immediately, assign `M` to `R`.

```cpp
int leftmostBinarySearch(vector<int>& arr, int T) {
 int L = 0, R = arr.size() - 1;
 int M;
 do{
  M = (L + R) / 2;
  int mid = arr[M];
  if (T <= mid) {
   R = M;
  }
  else if (T > mid) {
   L = M + 1;
  }
 } while (L < R);
 return L;
}
```

### Procedure for finding the rightmost element

```cpp
int leftmostBinarySearch(vector<int>& arr, int T) {
 int L = 0, R = arr.size() - 1;
 int M;
 do{
  M = (L + R) / 2;
  int mid = arr[M];
  if (T < mid) {
   R = M - 1;
  }
  else if (T >= mid) {
   L = M;
  }
 } while (L < R);
 return R;
}
```
