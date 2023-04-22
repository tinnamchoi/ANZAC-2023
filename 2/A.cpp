#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int mary_l, mary_r, marty_l, marty_r;
  cin >> mary_l >> mary_r >> marty_l >> marty_r;

  int each = 0;
  int over = 0;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp == 1) {
      cout << "No" << endl;
      return 0;
    }
    each += temp / 2;
    over += temp % 2;
  }

  if (each > mary_r || each > marty_r) {
    cout << "No" << endl;
    return 0;
  }

  int budget = mary_r + marty_r - each * 2;

  if (over > budget) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}