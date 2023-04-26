#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {


    int n; cin >> n;
    int m; cin >> m;

    int x;
    
    vector<int> passengers; passengers.push_back(0);

    for (int i = 0; i < n; i++) {
        cin >> x;
        passengers.push_back(x);
    }


    int i = 0;
    while (passengers[i] != m) i++;
    int target = i;

    if (m == target) { cout << 0 << endl; return 0; }

    int count = 1;
    while (m != target) {

        m = passengers[m];
        count++;

    }

    cout << count << endl;

    return 0;
}