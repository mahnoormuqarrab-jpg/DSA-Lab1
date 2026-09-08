#include <iostream>
#include <vector>
#include "modeArray.cpp"
using namespace std;

int main() {
    // Test 1: unique mode
    vector<int> arr1 = {1, 2, 2, 3, 2, 4};
    cout << "Test 1 (unique mode): " << findMode(arr1) << " (expected 2)" << endl;

    // Test 2: multiple modes (tie) - either valid answer is acceptable
    vector<int> arr2 = {1, 1, 2, 2, 3};
    cout << "Test 2 (multiple modes/tie): " << findMode(arr2) << " (1 or 2 both valid)" << endl;

    // Test 3: empty array
    vector<int> arr3;
    cout << "Test 3 (empty array): " << findMode(arr3) << " (expected -1)" << endl;

    return 0;
}
