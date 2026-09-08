#include <iostream>
#include <vector>
#include "findIndices.cpp"
using namespace std;

int main() {
    // Test 1: multiple occurrences
    vector<int> arr1 = {1, 2, 3, 2, 4, 2};
    vector<int> result1 = findAllIndices(arr1, 2);
    cout << "Test 1 (multiple occurrences): ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // Test 2: key not present
    vector<int> arr2 = {1, 2, 3};
    vector<int> result2 = findAllIndices(arr2, 9);
    cout << "Test 2 (key not present), size should be 0: " << result2.size() << endl;

    // Test 3: empty array
    vector<int> arr3;
    vector<int> result3 = findAllIndices(arr3, 1);
    cout << "Test 3 (empty array), size should be 0: " << result3.size() << endl;

    return 0;
}
