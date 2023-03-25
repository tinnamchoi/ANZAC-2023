#include <bits/stdc++.h>

using namespace std;

int main() {
  int digit;
  string num;
  cin >> digit;
  cin >> num;
  
  bool flag = false;

  for (int i = 0; i < num.size(); i++) {
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
