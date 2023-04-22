#include <bits/stdc++.h>

using namespace std;

int main(void){
    // parse input
    int rows, cols, idx;
    cin >> rows >> cols >> idx;
    vector<string> input;
    vector<string> ans;
    for (int i=0; i<rows; i++){
        string temp;
        cin >> temp;
        input.push_back(temp);
        ans.push_back("");
    }

    // get answer
    int left = idx-1, right = idx;
    while (left >= 0 && right < cols){
        // compare opposite edges for each row
        for (int i=0; i<rows; i++){
            if (input[i][left] == 'o' && input[i][right] == 'o'){
                ans[i] += 'o';
            } else {
                ans[i] += 'x';
            }
        }
        left--; right++;
    }

    // padding
    while (left >= 0){
        for (int i=0; i<rows; i++){
            ans[i] += input[i][left];
        }
        left--;
    }
    while (right < cols){
        for (int i=0; i<rows; i++){
            ans[i] += input[i][right];
        }
        right++;
    }

    // reverse answer
    for (auto str : ans){
        for (int i=str.length()-1; i >= 0; i--){
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}