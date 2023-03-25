#include <bits/stdc++.h>

using namespace std;

unordered_set<int> fib = {1, 2, 3, 5, 8};

void FBN(int num) {
  if (num != 1) {
    FBN(num - 1);
  }
  if (fib.find(num) != fib.end()) {
    cout << "fizz";
  } else {
    cout << "buzz";
  }
}

int main() {
  int num;
  cin >> num;

  FBN(num);
  cout << endl;

  return 0;
}
