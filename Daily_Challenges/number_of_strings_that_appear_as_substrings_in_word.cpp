#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {

    int count = 0;
    for (string &pat : patterns) {
        if (word.find(pat) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    int ans = numOfStrings(patterns, word);
    cout << ans;
    return 0;
}