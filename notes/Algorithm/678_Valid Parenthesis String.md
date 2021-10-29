---
title: "678. Valid Parenthesis String"
author: "SanWang"
date: "2021-10-29"
---

# 678. Valid Parenthesis String

## Description

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

## Solutions

### My Solution

```cpp
bool checkValidString(string s) {
    stack<char> st;
    vector<int> starPos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            if (st.empty()) {
                if (starPos.size() > 0) starPos.pop_back();
                else return false;
            }
            else st.pop();
        }
        else starPos.push_back(i);
    }
    bool res = true;
    for (int k = starPos.size() - 1; k >= 0; k--) {
        if (st.empty()) break;
        else {
            int leftPos = st.top();
            st.pop();
            int pos = starPos[k];
            if (leftPos > pos) return false;

        }
    }
    return res && st.empty();
}
```

### Other Solution

> `diff` is the difference between the count of '(' minus the count of ')'.
> `maxDiff++` when the character is '('
> `minDiff--` when the character is ')'

```cpp
bool checkValidString(string s) {
    int maxDiff = 0, minDiff = 0;
    for (char c : s) {
        maxDiff += (c == '(' || c == '*') ? 1 : -1;
        minDiff += (c == ')' || c == '*') ? -1 : 1;
        if (maxDiff < 0) return false;
        minDiff = max(0, minDiff);
    }
    return minDiff == 0;
}
```
