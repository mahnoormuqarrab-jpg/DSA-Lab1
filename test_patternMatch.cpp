#include <iostream>
#include <string>
#include "patternMatch.cpp"
using namespace std;

int main() {
    // Test 1: pattern at the beginning
    cout << "Test 1 (pattern at beginning): " << findPattern("hello world", "hello") << " (expected 0)" << endl;

    // Test 2: pattern at the end
    cout << "Test 2 (pattern at end): " << findPattern("hello world", "world") << " (expected 6)" << endl;

    // Test 3: pattern not present
    cout << "Test 3 (pattern not present): " << findPattern("hello world", "xyz") << " (expected -1)" << endl;

    // Test 4: empty pattern
    cout << "Test 4 (empty pattern): " << findPattern("hello world", "") << " (expected -1)" << endl;

    return 0;
}
