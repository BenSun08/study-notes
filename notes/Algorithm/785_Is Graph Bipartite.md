# 785. Is Graph Bipartite?

## Description

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

## Solutions

### My Solution

> When a graph is bipartite, all of its edges are linked between two set, therefore, when a vertex `u` is in set `A`, all the vertices in `graph[u]` must in the other set `B`. So I decide to recursively put each node in set `A` and `B`. During the process, if the current node expected to be put in the set, for example `A`, but it's already put in set `B`, then this graph is not bipartite.

```cpp
#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> g;
bool recur(int val, g& graph, int setIdx, vector<vector<bool>>& biBool, vector<bool>& done) {
 int nextIdx = (setIdx + 1) % 2;
 if (biBool[nextIdx][val]) return false;
 if (biBool[setIdx][val]) return true;

 biBool[setIdx][val] = true;
 done[val] = true;


 for (int i = 0; i < graph[val].size(); i++) {
  bool subVal = recur(graph[val][i], graph, nextIdx, biBool, done);
  if (!subVal) return false;
 }
 return true;
}

bool isBipartite(vector<vector<int>>& graph) {
 vector<vector<bool>> biBool(2, vector<bool>(graph.size(), false));
 vector<bool> done(graph.size(), false);

 int toDoIdx = 0;
 while (toDoIdx < done.size()) {
  bool can = recur(toDoIdx, graph, 0, biBool, done);
  if (!can) return false;
  for (toDoIdx = 0; toDoIdx < done.size(); toDoIdx++) {
   if (!done[toDoIdx]) break;
  }
 }
 return true;
}

int main() {
 g graph(4, vector<int>(2, 0));
 int arr[][2] = { { 1, 3 },{ 0,2 },{ 1,3},{0,2} };
 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 2; j++) {
   graph[i][j] = arr[i][j];
  }
 }
 bool res = isBipartite(graph);
 
 cout << "The graph is bipartie: " << res << endl;

 return 0;
}
```

### Other Solutions

#### BFS
