#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y, x_1, y_1, x_2, y_2;
  cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;

  int x_dist, y_dist;

  if ((x_1 <= x && x <= x_2) || (x_1 >= x && x >= x_2)) {
    x_dist = 0;
  } else {
    x_dist = min(abs(x - x_1), abs(x - x_2));
  }
  if ((y_1 <= y && y <= y_2) || (y_1 >= y && y >= y_2)) {
    y_dist = 0;
  } else {
    y_dist = min(abs(y - y_1), abs(y - y_2));
  }

  cout << fixed << setprecision(3) << sqrt(x_dist * x_dist + y_dist * y_dist)
       << endl;
}