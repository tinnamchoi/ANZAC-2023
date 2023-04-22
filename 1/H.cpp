#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<vector<bool>> v(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      v[i][j] = s[j] == 'D';
    }
  }

  vector<vector<int>> count(n, vector<int>(n - s + 1, 0));

  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < s; j++) {
      temp += v[i][j];
    }
    count[i][0] = temp;
    for (int j = 1; j < n - s + 1; j++) {
      count[i][j] = count[i][j - 1] - v[i][j - 1] + v[i][j + s - 1];
    }
  }

  vector<vector<int>> count2(n - s + 1, vector<int>(n - s + 1, 0));

  for (int i = 0; i < n - s + 1; i++) {
    int temp = 0;
    for (int j = 0; j < s; j++) {
      temp += count[j][i];
    }
    count2[0][i] = temp;
    for (int j = 1; j < n - s + 1; j++) {
      count2[j][i] = count2[j - 1][i] - count[j - 1][i] + count[j + s - 1][i];
    }
  }

  unordered_map<int, int> m;

  for (int i = 0; i < n - s + 1; i++) {
    for (int j = 0; j < n - s + 1; j++) {
      m[count2[i][j]]++;
    }
  }

  priority_queue<pair<int, int>> pq;
  for (auto i : m) {
    pq.push({0 - i.first, i.second});
  }

  while (!pq.empty()) {
    cout << 0 - pq.top().first << " " << pq.top().second << endl;
    pq.pop();
  }

  return 0;
}
