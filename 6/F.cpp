#include <bits/stdc++.h>

using namespace std;

int main() {
  int a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  int min1 = min(a1, min(b1, c1)), max1 = max(a1, max(b1, c1)), min2 = min(a2, min(b2, c2)), max2 = max(a2, max(b2, c2));
  int mid1 = a1 + b1 + c1 - min1 - max1, mid2 = a2 + b2 + c2 - min2 - max2;
  if (min1 != min2 || mid1 != mid2 || max1 != max2 || min1 * min1 + mid1 * mid1 != max1 * max1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
