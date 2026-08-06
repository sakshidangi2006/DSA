#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



void backtrack(string &digits, int n, int idx, string diary, vector<string>& ans, unordered_map<char,string>f) {
    
    if(idx == n) {
        ans.push_back(diary);
        return;
    }
    
    string choice = f[digits[idx]];
    for(int j = 0; j < choice.size(); j++) {
        diary.push_back(choice[j]);
        backtrack(digits, n, idx+1, diary, ans,f);
        diary.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char,string> f;
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";
    vector<string> ans;
    string diary = "";
    int idx = 0;
        
    backtrack(digits, digits.size(), idx, diary, ans,f);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for(string s : ans) {
        cout << s << " ";
    }
    return 0;
}