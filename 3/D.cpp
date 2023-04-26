#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v(3);
  for (int i = 0; i < 3; i++) {
    cin >> v[i];
  }
  vector<string> vec;
  set<string> ids;
  {
    unordered_map<string, int> umap;
    for (int j = 0; j < v[0]; j++) {
      string id; cin >> id;
      int count; cin >> count;
      if (umap.find(id) == umap.end()) {
        vec.push_back(id);
      }
      umap[id] += count;
    }
    for (auto p : umap) {
      if (p.second >= 20) {
        ids.insert(p.first);
      }
    }
  }
  for (int i = 1; i < 3; i++) {
    unordered_map<string, int> umap;
    for (int j = 0; j < v[i]; j++) {
      string id; cin >> id;
      int count; cin >> count;
      umap[id] += count;
    }
    for (auto p : umap) {
      if (p.second < 20) {
        ids.erase(p.first);
      }
    }
    for (auto it = ids.begin(); it != ids.end(); ++it) {
      if (umap.find(*it) == umap.end()) {
        string temp = *it;
        it--;
        ids.erase(temp);
      }
    }
  }
  cout << ids.size();
  for (string s : vec) {
    if (ids.find(s) != ids.end()) {
      cout << " " << s;
    }
  }
  cout << endl;
}