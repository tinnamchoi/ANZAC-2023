#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  string you, frd;
  cin >> you >> frd;

  int m = you.size();

  int set = 0;

  for (int i = 0; i < m; i++) {
    if (you[i] == frd[i]) {
      set++;
    }
  }

  cout << min(n, set) + m - max(n, set) << endl;
}