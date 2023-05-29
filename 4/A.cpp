#include <bits/stdc++.h>

using namespace std;

/* error conditions
 * 
 * Increment of scores after 11
 * Score decrease
 * 
 */

int main() {
  int n;
  cin >> n;
  
  int prev_a = 0, prev_b = 0;
  int error = 0;
  
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    
    if (error) {
      continue;
    }
    
    int a, b;
    
    for (int c = 0; c < s.size(); c++) {
      if (s[c] == '-') {
        a = stoi(s.substr(0, c));
        b = stoi(s.substr(c + 1, s.size() - c - 1));
        break;
      }
    }
    
    int sum = a + b;
    
    if (sum % 4 == 1 || sum % 4 == 2) {
      int temp = a;
      a = b;
      b = temp;
    }
    
    if (a == 11 && b == 11) {
      error = i;
    }
    
    if ((prev_a == 11 || prev_b == 11) && (prev_a != a || prev_b != b)) {
      error = i;
    }
    
    if (a < prev_a || b < prev_b) {
      error = i;
    }
    
    prev_a = a;
    prev_b = b;
  }
  
  if (error) {
    cout << "error " << error << endl;
  } else {
    cout << "ok" << endl;
  }
  
  return 0;
}
