---
title: "Josephus Problem"
author: "SanWang"
date: "2021-11-24"
---

# Josephus Problem

> *n* people in a circle waiting to be executed. Counting started at a specified position in the circle and proceeds around the circle at a specified direction. After a specified number of people skipped, the next person is executed. The procedure is repeated with the remaining people, starting with the next person, going with the same direction and skipping the same number of people, until only one person remains, and is freed.

## Solution

### Dynamic Programming

> - let $f(n, k)$ denotes the position of the final survivor. After the $k$-th person is killed, circle of $n-1$ people remains.
> - And the next count is started with position $(k + 1) mod n$, which is $(k mod n) + 1$.
> - The position of survivor in the remaining circle would be $f(n -1, k)$ if count started at position 1.
> - shifting this offset for the fact that the starting position is $(k mod n) + 1$ yields the recurrence:
$$
f(n, k) = ((f(n - 1, k) + k - 1) mod n) + 1
$$
with
$$
f(1, k) = 1
$$

let $g(n ,k)$ denote the position of the survivor when starting point is 0:
$$
g(n, k) = (g(n - 1, k) + k) mod n
$$
with
$$
g(1, k) = 0
$$

### Implementation

```cpp
int findWinner(int n, int k) {
  int res = 0;
  for(int i = 2; i <= n; i++) {
    res = (res + k) % i;
  }
  return res + 1;
}
```
