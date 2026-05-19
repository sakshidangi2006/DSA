#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;


int maxNumberOfBalloons(string text) {
    int n = text.size();
    int ans = INT_MAX;

    unordered_map<char,int>have,need;

    for(char ch: text) {
        have[ch]++;
    }
    
    need['b'] = 1;
    need['a'] = 1;
    need['l'] = 2;
    need['o'] = 2;
    need['n'] = 1;

    for(auto i: need) {
        char ch = i.first;
        int needFreq = i.second;
        int haveFreq = have[ch];
        int times = haveFreq / needFreq;
        ans = min(times,ans);
    }

    return ans;

}

int main() {
    string text = "loonbalxbalpoonl";
    int ans = maxNumberOfBalloons(text);
    cout << ans;
    return 0;
}