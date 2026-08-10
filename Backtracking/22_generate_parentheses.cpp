#include <iostream>
#include <vector>
using namespace std;


void backtrack(int n, int open, int close, string diary,
vector<string>& ans) {

    if(diary.size() == 2*n) {
        ans.push_back(diary);
        return;
    }

    if(open < n) {
        diary.push_back('(');
        backtrack(n, open+1, close, diary, ans);
        diary.pop_back();
    }

    
    if(close < open) {
        diary.push_back(')');
        backtrack(n, open, close+1,  diary, ans);
        diary.pop_back();
    }

}

vector<string> generateParenthesis(int n) {
    int open = 0;
    int close = 0;
    vector<string>ans;
    string diary = "";
    backtrack(n, 0, 0, diary, ans);
    return ans;
}


int main() {
    int n = 3;
    vector<string>ans = generateParenthesis(n);
    for(string s : ans) {
        cout << s <<" ";
    }
    return 0;
}