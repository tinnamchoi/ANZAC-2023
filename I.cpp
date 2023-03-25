#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  
  vector<vector<int>> v(m, vector<int>(n));
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || i == m - 1 || j == 0 || j == n - 1 || v[i][j] > v[i][j+1] || v[i][j] > v[i+1][j] || v[i][j] > v[i][j-1] || v[i][j] > v[i-1][j]) {
        cout << 0;
      } else {
        cout << 1;
      }
      if (j != n - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
  
}