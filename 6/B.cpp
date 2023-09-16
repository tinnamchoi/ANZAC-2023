#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s, queries;
  cin >> n >> s;
  vector<vector<int>> alist(n, vector<int> ());
  vector<vector<int>> coats(n, vector<int> (2));
  for (int i = 0; i < n; i++) {
    cin >> coats[i][0] >> coats[i][1];
    for (int j = 0; j < i; j++) {
      if (coats[j][0] == coats[i][0] || coats[j][1] == coats[i][1]) {
        alist[j].push_back(i);
        alist[i].push_back(j);
      }
    }
  }
  cin >> queries;
  while (queries--) {
    int start, end;
    cin >> start >> end;
    start--;
    end--;
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);
    visited[start] = true;
    q.push({start, 0});
    int ans = -1;
    while (!q.empty()) {
      int curr, length;
      tie(curr, length) = q.front();
      if (curr == end) {
        ans = length;
        break;
      }
      q.pop();
      for (int & a : alist[curr]) {
        if (!visited[a]) {
          q.push({a, length + 1});
          visited[a] = true;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}