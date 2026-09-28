#include <iostream>
#include <algorithm>
using namespace std;

int maxDepth(string s) {
    int depth = 0;
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            depth++;
            ans = max(ans, depth);
        }

        else if(s[i] == ')') depth--;
    }
    return ans;
}

int main() {
    string s = "(1+(2*3)+((8)/4))";
    int ans = maxDepth(s);
    cout << ans;
    return 0;
}