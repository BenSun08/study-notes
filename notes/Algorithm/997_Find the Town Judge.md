# 997. Find the Town Judge

In a town, there are n people labelled from 1 to n.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

## Related Topic

### Graph

important concepts: **indegree** and **outdegree**.

## Solution

### My Solution

 1. use `map` to map every presumed judge to all other residents.
 2. loop over the trust vector, erase the map key and mapped value if the the resident exists in the presumed judges list.
 3. if the newly added presumed judge is in the recorded residents list(using `set`), omit it and jump to the next loop.
 4. finally if there is a presumed judge that has n -1 residents, that is the answer.

```cpp
#include<iostream>
#include <vector>
#include<map>
#include<set>
using namespace std;

int findTownJudge(int n, vector<vector<int>> &trust) {
 if (n == 1) return 1;
 map<int, vector<int>> trustMap;
 set<int> rsds;
 int premJudge;
 int resident;
 for (int i = 0; i < trust.size(); i++) {
  premJudge = trust[i][1];
  resident = trust[i][0];
  rsds.insert(resident);
  if (trustMap.find(resident) != trustMap.end()) {
   trustMap.erase(resident);
  }
  if (rsds.find(premJudge) != rsds.end()) {
   continue;
  }
  else {
   if (trustMap.find(premJudge) == trustMap.end()) {
    trustMap[premJudge] = vector<int>({ resident });
   }
   else {
    trustMap[premJudge].push_back(resident);
   }
  }
 }
 for (map<int, vector<int>>::iterator it = trustMap.begin(); it != trustMap.end(); ++it) {
  if (it->second.size() ==  n - 1) {
   return it->first;
  }
 }
 return -1;
}

int main() {
 int n = 4;
 vector<vector<int>> trust ({ { 1,3 } ,{ 1,4 }, { 2,3 },{ 2,4 },{ 4,3 } });
 cout << "The Town Judge is:" << findTownJudge(n, trust) << endl;

 return 0;
}
```

### Recommended Solution

*indegree* and *outdegree*
consider each resident is a node in graph, so the judge must has n -1 indegree and 0 outdegree.

```cpp
int findTownJudge(int n, vector<vector<int>> &trust) {
 vector<vector<int>> degrees(n, { 0, 0 }); // degrees[i][0] is outdegree, degrees[i][1] is indegree
 for (int i = 0; i < trust.size(); i++) {
  degrees[trust[i][0] - 1][0]++;
  degrees[trust[i][1] - 1][1]++;
 }
 for (int j = 0; j < degrees.size(); j++) {
  if (degrees[j][0] == 0 && degrees[j][1] == n - 1) {
   return j + 1;
  }
 }
 return -1;
}
```
