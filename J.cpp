#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s, m, max_m = 0;
  
  cin >> n >> s;
  while (n--) {
    cin >> m;
    max_m = max(max_m, m);
  }
  
  cout << (max_m * s + 999) / 1000 << endl;
}