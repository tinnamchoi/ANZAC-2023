#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream myfile;
  myfile.open ("primes.txt");

  string s;
  int j = 0;
  
  for (int i = 1; i <= 1000000; i++) {
    if (primes[j] == i) {
      s += '1';
      j++;
      continue;
    } else {
      s += '0';
    }
  }
  
  reverse(s.begin(), s.end());
  
  myfile << s;

  myfile.close();
  return 0;

}
