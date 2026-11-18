#include <iostream>
using namespace std;


int minChanges(string s) {
    int n = s.size();
    int changes = 0;
    int prevVal = s[0];
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) {
            prevVal = s[i];
        }
        if(i % 2 == 1 && s[i] != prevVal){
            changes++;
            s[i] = prevVal;
        }
    }
    return changes;
}

int main() {
    string s = "1001";
    int ans = minChanges(s);
    cout << ans;
    return 0;
}