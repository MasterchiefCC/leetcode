#include "mod.h"
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>ret;
        int len=input.size();
        for(int i=0; i<len; ++i){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){

                vector<int>left=diffWaysToCompute(input.substr(0, i));
                vector<int>right=diffWaysToCompute(input.substr(i+1));
                
                for(int j=0; j<left.size(); ++j){
                    for(int k=0; k<right.size(); ++k){
                        if(input[i]=='+')ret.push_back(left[j]+right[k]);
                        else if(input[i]=='-')ret.push_back(left[j]-right[k]);
                        else ret.push_back(left[j]*right[k]);
                    }
                }
            }
        }
        if(ret.empty())ret.push_back(atoi(input.c_str()));
        return ret;
    }
};

int main(){
    Solution a;
    vector<int> s=a.diffWaysToCompute("2-1-1");
    for(int i=0; i<s.size(); ++i)
        printf("%d\n", s[i]);
    return 0;
}