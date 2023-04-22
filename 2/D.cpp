#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int ans = 0;
  
  while (n--) {
    string word;
    cin >> word;
    vector<bool> seen(26, false);
    for (char & c : word) {
      if (seen[c - 'A'] || c - 'A' >= m) {
        goto next;
      }
      seen[c - 'A'] = true;
    }
    ans++;
    next:;
  }
  
  cout << ans << endl;
}