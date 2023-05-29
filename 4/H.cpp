#include <bits/stdc++.h>

using namespace std;

long find(vector<long>& v, int& n, int index) {
  int left = index;
  int right = index;
  
  while (true) {
    if (left - 1 >= 0 && v[left - 1] <= v[left]) {
      left--;
    }
    if (right + 1 < n && v[right + 1] <= v[right]) {
      right++;
    }
    if ((left - 1 < 0 || v[left - 1] > v[left]) && 
        (right + 1 >= n || v[right + 1] > v[right])) {
      break;
    }
    if ((left - 1 >= 0 && v[left - 1] > v[left] && v[right] < v[left]) ||
        (right + 1 < n && v[right + 1] > v[right] && v[left] < v[right])) {
      break;
    }
  }
  return min(v[index] - v[left], v[index] - v[right]);
}

int main() {
  int n;
  cin >> n;
  vector<long> v(n);
  long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i - 1]) {
      ans = max(ans, find(v, n, i - 1));
    }
  }
  cout << ans << endl;
  return 0;
}