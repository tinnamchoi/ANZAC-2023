#include <bits/stdc++.h>

using namespace std;

int main() {
  int digit;
  string num;
  cin >> digit;
  cin >> num;
  
  bool flag = false;

  for (long long unsigned int i = 0; i < num.length(); i++) {
    if (digit > num[i] - '0' && !flag) {
      cout << digit;
      flag = true;
    }
    cout << num[i];
  }
  
  if (!flag) {
    cout << digit;
  }
  
  cout << endl;
  return 0;
}
