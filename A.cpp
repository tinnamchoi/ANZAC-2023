#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v1(5);
  vector<int> v2(5);
  for (int i = 0; i < 5; i++) {
    cin >> v1[i];
  }
  for (int i = 0; i < 5; i++) {
    cin >> v2[i];
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans += v1[i] > v2[i];
  }
  cout << ans << endl;
}