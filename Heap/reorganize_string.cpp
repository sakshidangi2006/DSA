#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string reorganizeString(string s) {

    unordered_map<char,int> freq;
    for(char ch : s)
        freq[ch]++;

    priority_queue<pair<int,char>> pq;
    for(auto &p : freq)
        pq.push({p.second, p.first});

    string ans;
    pair<int,char> prev = {0, '#'}; 
    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        ans.push_back(curr.second);
        curr.first--;
        if(prev.first > 0)
            pq.push(prev);
        prev = curr;
    }

    if(ans.size() != s.size())
        return "";
    return ans;
}

int main() {
    string s = "aab";
    string ans = reorganizeString(s);
    cout << ans;
    return 0;
}