#include <vector>
#include <map>
using namespace std;

int findMode(vector<int> arr) {
    if (arr.size() == 0) {
        return -1; // no mode for empty array
    }

    map<int, int> counts;
    for (int i = 0; i < arr.size(); i++) {
        counts[arr[i]]++;
    }

    int mode = arr[0];
    int maxCount = 0;

    for (auto it = counts.begin(); it != counts.end(); it++) {
        if (it->second > maxCount) {
            maxCount = it->second;
            mode = it->first;
        }
    }

    return mode;
}
