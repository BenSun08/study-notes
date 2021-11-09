# Topological Sort

## Application

> Its main application is in scheduling a sequence of jobs or tasks based on their dependencies.

## Algorithms

### Kahn's Algorithm

or BFS

 1. find start nodes that have no incoming edge and insert them into a set `S`.

 2. while `S` is not empty, for each node in the set, find all its outdegree and corresponding nodes, decrease their indegrees by 1. If the indegree equal to 0, put that node in `S`.

 3. finally, if all the nodes's indegree is equal to 0, then it's a DAG(**directed acyclic graph**), otherwise it's not.

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

### Deep-First Algorithm

1. visit each unmarked node

2. mark it as todo

3. visit all its prerequisites/subnodes recusively, if there is a prerequisit is already marked as todo, then the graph is not a DAG(*directed acyclic graph*).

4. mark it as done

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
