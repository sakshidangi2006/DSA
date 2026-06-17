#include <iostream> 
#include <vector>
using namespace std;


vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
   
   vector<int>freq(A.size()+1,0);
   vector<int>ans(A.size());

   int common = 0;

   for(int i = 0; i < A.size(); i++) {
       freq[A[i]]++;

       if(freq[A[i]] == 2) common++;

       freq[B[i]]++;

       if(freq[B[i]] == 2) common++;

       ans[i] = common;
   }

   return ans;

}

int main() {
    vector<int>A = {3,1,2,4};
    vector<int>B = {1,3,2,4};
    vector<int>C = findThePrefixCommonArray(A,B);
    for(int i = 0; i < C.size(); i++) {
        cout<< C[i]<<" ";
    }
    return 0;
}
