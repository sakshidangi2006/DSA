#include <iostream>
#include <vector>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    int depth = 0;
    vector<int>ans;

    for(char ch : seq) {
        if(ch=='(') {
            depth++;
            ans.push_back(depth % 2);
        }
        else if(ch == ')') {
            ans.push_back(depth % 2);
            depth--;
        }
    }
    return ans;
}

int main() {
    string seq = "()(())()";
    vector<int> ans = maxDepthAfterSplit(seq);
    cout << "[";
    for(int a : ans) {
        cout << a <<" ";
    }
    cout <<"]";
    return 0;
}