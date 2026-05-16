#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s, int k) {
        
    stack<pair<char, int>> st;

    for(char ch : s) {

        if(st.empty() || st.top().first != ch) {
            st.push({ch, 1});
        }
        else {
            st.top().second++;

            if(st.top().second == k) {
                st.pop();
            }
        }
    }

    string ans = "";

    while(!st.empty()) {
        char ch = st.top().first;
        int cnt = st.top().second;

        ans = string(cnt, ch) + ans;
        st.pop();
    }

    return ans;
}

int main() {
    string s = "deeedbbcccbdaa";
    int k = 3;
    string ans = removeDuplicates(s,k);
    cout << ans;
    return 0;
}
