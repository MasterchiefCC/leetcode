#include "mod.h"
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if(A.size()<2)return true;
        for(int i=0, maxn=INT_MIN; i<A.size()-2; ++i){
            maxn=max(A[i], maxn);
            if(maxn>A[i+2])return false;
        }
        return true;
    }
};
int main(){
    vector<int>A={2,0,1};
    Solution test;
    cout<<(test.isIdealPermutation(A)?"true":"false")<<endl;

    return 0;
}