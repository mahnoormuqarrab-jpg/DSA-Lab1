#include <iostream>
#include <vector>
#include "pascalTriangle.cpp"
using namespace std;

void printTriangle(vector<vector<int>> triangle) {
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Test 1: n = 0" << endl;
    vector<vector<int>> t0 = generatePascal(0);
    printTriangle(t0);
    cout << "Rows generated: " << t0.size() << " (expected 0)" << endl << endl;

    cout << "Test 2: n = 1" << endl;
    vector<vector<int>> t1 = generatePascal(1);
    printTriangle(t1);
    cout << endl;

    cout << "Test 3: n = 5" << endl;
    vector<vector<int>> t5 = generatePascal(5);
    printTriangle(t5);
    cout << "Row 5 (last row) should be: 1 4 6 4 1" << endl;

    return 0;
}

