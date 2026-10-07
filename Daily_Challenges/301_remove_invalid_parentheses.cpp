#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

unordered_set<string> st;

void backtrack(string &s, int idx, int count, int &maxLen, string &curr) {

    if (count < 0)
        return;

    if (idx == s.size()) {
        if (count == 0) {
            if (curr.size() > maxLen) {
                maxLen = curr.size();
                st.clear();
                st.insert(curr);
            }
            else if (curr.size() == maxLen) {
                st.insert(curr);
            }
        }
        return;
    }

    if (s[idx] != '(' && s[idx] != ')') {
        curr.push_back(s[idx]);
        backtrack(s, idx + 1, count, maxLen, curr);
        curr.pop_back();
        return;
    }

    curr.push_back(s[idx]);

    if (s[idx] == '(')
        backtrack(s, idx + 1, count + 1, maxLen, curr);
    else
        backtrack(s, idx + 1, count - 1, maxLen, curr);

    curr.pop_back();

    backtrack(s, idx + 1, count, maxLen, curr);
}

vector<string> removeInvalidParentheses(string s) {
    st.clear();

    int maxLen = 0;
    string curr = "";

    backtrack(s, 0, 0, maxLen, curr);

    return vector<string>(st.begin(), st.end());
}

int main() {
    string s = "()())()";
    vector<string> ans = removeInvalidParentheses(s);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<"\n";
    }
    return 0;
}
