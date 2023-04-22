#include <bits/stdc++.h>

using namespace std;

bool search(int cur, int mary, int marty, vector<int>& sushi, int mary_left, int mary_right, int marty_left, int marty_right){
    // if the end
    if (mary > mary_right || marty > marty_right) return false;
    if (cur == sushi.size()){
        if (mary >= mary_left && marty >= marty_left) return true;
        return false;
    }
    // if even
    bool ans = false;
    if (sushi[cur]%2==0){
        int t = sushi[cur]/2;
        ans |= search(cur+1,mary+t,marty+t,sushi,mary_left,mary_right,marty_left,marty_right);
    } else{
        int t = sushi[cur]/2;
        ans |= search(cur+1,mary+t,marty+t+1,sushi,mary_left,mary_right,marty_left,marty_right);
        ans |= search(cur+1,mary+t+1,marty+t,sushi,mary_left,mary_right,marty_left,marty_right);
    }
    return ans;
}

int main() {
  int n;
  cin >> n;

  int mary_l, mary_r, marty_l, marty_r;
  cin >> mary_l >> mary_r >> marty_l >> marty_r;

  vector<int> sushi(n, 0);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    sushi[i] = temp;
  }
  sort(sushi.begin(),sushi.end(),greater<int>());

  // simulate
  if (search(0,0,0,sushi,mary_l, mary_r, marty_l, marty_r)){
    cout << "Yes" << endl;
  } else{
    cout << "No" << endl;
  }
  return 0;
}