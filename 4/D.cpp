#include <bits/stdc++.h>

using namespace std;

int main() {
  long n;
  cin >> n;
  long mid = n * sqrt(2) / 2 + 1;
  pair<long, long> ans;
  long ans_dist = LONG_MAX;
  for (long i = 1; i <= mid; i++) {
    long height = sqrt((n - i) * (n + i)) + 1;
    if (height * height + i * i < ans_dist) {
      ans = {i, height};
      ans_dist = height * height + i * i;
    }
  }
  cout << ans.first << " " << ans.second << endl;
}