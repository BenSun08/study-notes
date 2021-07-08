# 207. Course Schedule

## Description

> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array  prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

> For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
> Return true if you can finish all courses. Otherwise, return false.

## Solution

### My Solution

Using Kahn's Algorithm.

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef unordered_map<int, int> intmap;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
 vector<vector<intmap>> courses;
 for (int i = 0; i < numCourses; i++) {
  intmap in;
  intmap out;
  vector<intmap> temp;
  temp.push_back(in);
  temp.push_back(out);
  courses.push_back(temp);
 }

 for (vector<int> pre : prerequisites) {
  int currC = pre[0];
  int prevC = pre[1];
  courses[prevC][1].insert({ currC, currC });
  courses[currC][0].insert({ prevC, prevC });
 }

 vector<int> noPrevCs;
 for (int i = 0; i < numCourses; i++) {
  vector<intmap> temp = courses[i];
  if (temp[0].size() == 0) {
   noPrevCs.push_back(i);
  }
 }
 if (noPrevCs.size() == 0) return false;

 while (noPrevCs.size() > 0)
 {
  int curr = noPrevCs[0];
  noPrevCs.erase(noPrevCs.begin());

  vector<intmap>* currC = &courses[curr];
  while (currC->at(1).size() > 0) {
   int toLearn = currC->at(1).begin()->first;
   currC->at(1).erase(toLearn);

   vector<intmap>* inC = &courses[toLearn];
   inC->at(0).erase(curr);
   if (inC->at(0).size() == 0 && inC->at(1).size() > 0) {
    noPrevCs.push_back(toLearn);
   }
  }
 }

 for (vector<intmap> c: courses) {
  if (c[0].size() > 0 || c[1].size() > 0) {
   return false;
  }
 }
 return true;
}

int main() {
 vector<vector<int>> pre;
 int arr[] = { 1, 0, 0, 1 };
 int len = sizeof(arr) / sizeof(int);
 int cNum = 2;

 for (int i = 0; i < len/2; i++) {
  vector<int> temp;
  for (int j = 0; j < 2; j++) {
   temp.push_back(arr[j + 2 * i]);
  }
  pre.push_back(temp);
 }
 cout << "Can the courses be finished?: " << canFinish(cNum, pre) << endl;
 return 0;
}
```

### Other Solutions

#### DFS

- visit each unmarked node
- mark it as todo
- visit all its prerequisites recusively, if there is a prerequisit is already marked as todo, then the graph is not a DAG(*directed acyclic graph*).
- mark it as done

```cpp
typedef vector<vector<int>> graph;
bool acyclic(graph &g, vector<bool> &todo, vector<bool> &done, int n) {
 if (done[n]) return true;
 if (todo[n]) return false;
 todo[n] = true;
 for (int pre : g[n]) {
  bool can = acyclic(g, todo, done, pre);
  if (!can) return false;
 }
 done[n] = true;
 return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
 graph g(numCourses);
 vector<bool> todo(numCourses, false);
 vector<bool> done(numCourses, false);

 for (vector<int> p : prerequisites) {
  g[p[1]].push_back(p[0]);
 }

 bool can = true;
 for (int i = 0; i < numCourses; i++) {
  if (!done[i]) {
   can = acyclic(g, todo, done, i);
   if (!can) break;
  }
 }
 return can;
}
```

#### BFS

*aka. Kahn's algorithm*

```cpp
typedef vector<vector<int>> graph;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
 graph g(numCourses);
 vector<int> inDegrees(numCourses, 0);

 for (vector<int> p : prerequisites) {
  g[p[1]].push_back(p[0]);
  inDegrees[p[0]]++;
 }

 queue<int> q;
 for (int i = 0; i < numCourses; i++) {
  if (inDegrees[i] == 0) {
   q.push(i);
  }
 }
 while (!q.empty()) {
  int curr = q.front();
  q.pop();
  numCourses--;

  for (int j = 0; j < g[curr].size(); j++) {
   inDegrees[g[curr][j]]--;
   if (inDegrees[g[curr][j]] == 0) {
    q.push(g[curr][j]);
   }
  }
 }
 return numCourses == 0;
}
```
