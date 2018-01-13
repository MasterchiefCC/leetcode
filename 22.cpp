#include "mod.h"
class Solution {
    vector<string>result;
    void genertor(int left, int right, string s, const int& n){
        if(right==n)result.push_back(s);
        else{
            if(left<n)
                genertor(left+1, right, s+'(', n);
            if(right<left)
                genertor(left, right+1, s+')', n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        string temp;
        genertor(0, 0, temp, n);
        return result;
    }
};