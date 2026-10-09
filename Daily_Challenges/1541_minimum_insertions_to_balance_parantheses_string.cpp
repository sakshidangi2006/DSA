#include <iostream>
using namespace std;


int minInsertions(string s) {
    int ans = 0;
    int require = 0;

    for(char ch : s) {

        if(ch == '(') {
            if(require % 2 == 1) {
                ans++;
                require--;
            }
            
             require += 2;
            
        }

        else {
            require--;
            if(require < 0) {
                ans += 1;
                require = 1;
            }
        }
    }
    return ans += require;
}

int main() {
    string s = "(()))";
    int ans = minInsertions(s);
    cout << ans;
    return 0;
}
