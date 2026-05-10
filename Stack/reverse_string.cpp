#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    stack<char>st;
    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }
    int i = 0;
    while(!st.empty()) {
        char c = st.top();
        st.pop();
        s[i] = c;
        i++;
    }
    
}

int main() {
    vector<char>s = {'h','e','l','l','o'};
    reverseString(s);
    return 0;
}