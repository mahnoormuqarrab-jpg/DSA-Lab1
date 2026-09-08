#include <string>
using namespace std;

int findPattern(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        return -1;
    }

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}
