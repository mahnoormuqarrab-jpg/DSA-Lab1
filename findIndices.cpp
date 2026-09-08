#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(vector<int> arr, int key) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            result.push_back(i);
        }
    }
    return result;
}
