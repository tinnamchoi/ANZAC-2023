#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  int max_m = 0;

  while (n--) {
    int m;
    cin >> m;
    max_m = max(max_m, m);
  }

  cout << (max_m * s + 999) / 1000 << endl;
}
