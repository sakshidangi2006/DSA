#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string,string> f;

    for(int i = 0; i < knowledge.size(); i++) {
        f[knowledge[i][0]] = knowledge[i][1];
    }

    string ans;

    for(int i= 0; i < s.size(); i++) {

        if(s[i] == '(') {
            int j = i+1;

            while(s[j] != ')') j++;

            string key = s.substr(i+1, j-i-1);

            if(f.find(key) != f.end()) {
                ans += f[key];
            }
            else {
                ans += "?";
            }
            i = j;
        }

        else ans += s[i];
    }
    return ans;
}

int main() {
    string s = "(name)is(age)yearsold.";
    vector<vector<string>>knowledge = {{"name","bob"},{"age","two"}};
    string ans = evaluate(s, knowledge);
    cout << ans;
    return 0;
}