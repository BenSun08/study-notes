# 1222. Queens That Can Attack the King

## Description

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.

### Solutions

#### My Solution

> loop over queens

```cpp
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
  vector<vector<int>> res(8);
  int kX = king[0];
  int kY = king[1];
  for (int i = 0; i < queens.size(); i++) {
    int qX = queens[i][0];
    int qY = queens[i][1];
    int dX = qX - kX;
    int dY = qY - kY;
    if(qY > kY && qX == kX) {
      if(res[0].size() == 0 || res[0][1] > qY) {
        res[0] = queens[i];
      }
    }
    else if(dX == dY && dY > 0) {
      if(res[1].size() == 0 || res[1][1] > qY) {
        res[1] = queens[i];
      }
    }
    else if(qY == kY && qX > kX) {
      if(res[2].size() == 0 || res[2][0] > qX) {
        res[2] = queens[i];
      }
    }
    else if(dX == -dY && dX > 0) {
      if(res[3].size() == 0 || res[3][0] > qX) {
        res[3] = queens[i];
      }
    }
    else if(qX == kX && qY < kY ) {
      if(res[4].size() == 0 || res[4][1] < qY) {
        res[4] = queens[i];
      }
    }
    else if(dX == dY && dX < 0) {
      if(res[5].size() == 0 || res[5][1] < qY) {
        res[5] = queens[i];
      }
    }
    else if(qY == kY && dX < 0) {
      if(res[6].size() == 0 || res[6][0] < qX) {
        res[6] = queens[i];
      }
    }
    else if(dX == -dY && dX < 0) {
      if(res[7].size() == 0 || res[7][0] < qX) {
        res[7] = queens[i];
      }
    }
  }

  vector<vector<int>> attackable;
  for(vector<int> it:res) {
  if(it.size() > 0) {
    attackable.push_back(it);
    }
  }
  return attackable;
}
```

#### Other Solution

> begin at queen and explore

```cpp
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
 vector<vector<int>> res;
 vector<vector<bool>> board(8, vector<bool>(8, false));
 for (auto q : queens) board[q[0]][q[1]] = true;
 for (int i = -1; i < 2; i++) {
  for (int j = -1; j < 2; j++) {
   if (i == 0 && j == 0) continue;
   int x = king[0] + i;
   int y = king[1] + j;
   while (min(x, y) >= 0 && max(x, y) < 8) {
    if (board[x][y]) {
     vector<int> tmp(2, x);
     tmp[1] = y;
     res.push_back(tmp);
     break;
    }
    x += i;
    y += j;
   }
  }
 }
 return res;
}
```
