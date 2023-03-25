#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;

  int m = s1.size();
  int set = 0;

  for (int i = 0; i < m; i++) {
    set += s1[i] == s2[i];
  }

  cout << m - abs(n - set) << endl;
}
