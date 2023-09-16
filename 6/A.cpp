#include <bits/stdc++.h>

using namespace std;

int h, r, a, w;

const double epsilon = 1e-6;

double ternarySearch(double left, double right,
                     const function<double(double)>& f) {
  while (right - left > epsilon) {
    double mid1 = left + (right - left) / 3;
    double mid2 = right - (right - left) / 3;

    double f_mid1 = f(mid1);
    double f_mid2 = f(mid2);

    if (f_mid1 < f_mid2) {
      right = mid2;
    } else {
      left = mid1;
    }
  }

  return (left + right) / 2;
}

int main() {
  cin >> h >> r >> a >> w;

  auto f = [](double mid) {
    double x1 = mid / 2, x2 = h - (h - mid) / 2;
    double m1 = w * mid, m2 = a * (h - mid);
    return (m1 * x1 + m2 * x2) / (m1 + m2);
  };

  double result = ternarySearch(0, h, f);

  cout << fixed << setprecision(6) << result << endl;
  return 0;
}