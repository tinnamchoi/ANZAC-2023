#include <bits/stdc++.h>

using namespace std;

double f(vector<double>& v, int index, int pass) {
  if (index == v.size() || pass <= 0) {
    return (pass <= 0);
  }
  
  double ans1 = 0, ans11, ans12;
  ans11 = f(v, index + 1, pass - 1) * v[index];
  ans12 = f(v, index + 1, pass + 1) * (1 - v[index]);
  ans1 = ans11 + ans12;
  
  double ans2 = f(v, index + 1, pass);
  
  
  return max(ans1, ans2);
}

int main() {
  int n, pass;
  cin >> n >> pass;
  
  vector<double> v(n);
  
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  printf("%lf\n", f(v, 0, pass));
}
