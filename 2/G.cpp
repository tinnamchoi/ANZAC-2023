#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<string> maze(n);
  
  for (int i = 0; i < n; i++) {
    cin >> maze[i];
  }
  
  queue<tuple<int, int, int>> q; // x, y, dist
  
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  
  for (int i = 1; i < n; i++) {
    if (maze[i + 1][0] == '.' && !visited[i + 1][0]) {
      q.push({i, 0, 1});
    }
    if (maze[0][i + 1] == '.') {
      q.push({0, i, 1});
    }
    visited[i][0] = true;
    visited[0][i] = true;
  }
  
  while (!q.empty()) {
    tuple<int, int, int> cur = q.front();
    q.pop();
    
    int x = get<0>(cur), y = get<1>(cur), dist = get<2>(cur);
    
    if (x == n - 1 && y == n - 1) {
      cout << dist << endl;
      return 0;
    }
    
    // up
    if (x > 0 && maze[x - 1][y] == '.' && !visited[x - 1][y]) {
      for (int i = x - 1; i >= 0; i--) {
        // if has branch, add as node
        if ((y > 0 && maze[i][y - 1] == '.' && !visited[i][y - 1]) || (y < n - 1 && maze[i][y + 1] == '.' && !visited[i][y + 1])) {
          q.push({i, y, dist + 1});
        }
        visited[i][y] = true;
      }
    }
    
    // down
    if (x < n - 1 && maze[x + 1][y] == '.' && !visited[x + 1][y]) {
      for (int i = x + 1; i < n; i++) {
        // if is bottom right, end
        if (i == n - 1 && y == n - 1) {
          cout << dist + 1 << endl;
          return 0;
        }
        // if has branch, add as node
        if ((y > 0 && maze[i][y - 1] == '.' && !visited[i][y - 1]) || (y < n - 1 && maze[i][y + 1] == '.' && !visited[i][y + 1])) {
          q.push({i, y, dist + 1});
        }
        visited[i][y] = true;
      }
    }
    
    // left
    if (y > 0 && maze[x][y - 1] == '.' && !visited[x][y - 1]) {
      for (int i = y - 1; i >= 0; i--) {
        // if has branch, add as node
        if ((x > 0 && maze[x - 1][i] == '.' && !visited[x - 1][0]) || (x < n - 1 && maze[x + 1][i] == '.' && !visited[x + 1][i])) {
          q.push({x, i, dist + 1});
        }
        visited[x][i] = true;
      }
    }
    
    // right
    if (x < n - 1 && maze[x + 1][y] == '.' && !visited[x + 1][y]) {
      for (int i = x + 1; i < n; i++) {
        // if is bottom right, end
        if (x == n - 1 && i == n - 1) {
          cout << dist + 1 << endl;
          return 0;
        }
        // if has branch, add as node
        if ((x > 0 && maze[x - 1][i] == '.' && !visited[x - 1][0]) || (x < n - 1 && maze[x + 1][i] == '.' && !visited[x + 1][i])) {
          q.push({x, i, dist + 1});
        }
      }
    }
    
    return 0;
  }
}