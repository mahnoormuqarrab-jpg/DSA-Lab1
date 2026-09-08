#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int n) {
    vector<vector<int>> triangle;

    for (int row = 0; row < n; row++) {
        vector<int> currentRow(row + 1);
        currentRow[0] = 1;
        currentRow[row] = 1;

        for (int j = 1; j < row; j++) {
            currentRow[j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}
