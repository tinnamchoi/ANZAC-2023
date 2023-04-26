#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {

    vector<int> weights(4); int n;

    cin >> weights[0]; cin >> weights[1]; cin >> weights[2]; cin >> weights[3]; cin >> n;

    vector<int> marks(4);
    vector<int> totals(4);

    for (int i = 0; i < n; i++) {
        string type; cin >> type;
      
        string nothing; cin >> nothing; 
        string grade_string; cin >> grade_string;
        string grade_1; string grade_2;

        int c = 0;
        while (grade_string[c] != '/') {
            grade_1 += grade_string[c];
            c++;
        }

        c++;

        while (c < grade_string.size()) {
            grade_2 += grade_string[c];
            c++;
        }


        if (type == "Lab") {

            marks[0] += stoi(grade_1);
            totals[0] += stoi(grade_2);
            
        } else if (type == "Hw") {
            
            marks[1] += stoi(grade_1);
            totals[1] += stoi(grade_2);

        } else if (type == "Proj") {

            marks[2] += stoi(grade_1);
            totals[2] += stoi(grade_2);

        } else {
            
            marks[3] += stoi(grade_1);
            totals[3] += stoi(grade_2);

        }
    }

    double final_grade = 0;

    for (int i = 0; i < 4; i++) {

        final_grade += (double)marks[i]/totals[i] * weights[i];
    }

    cout << (int)final_grade << endl;

    return 0;
}