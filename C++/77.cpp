#include "mod.h"

class Solution {
    void helper(const int &range, const int &len, int cur_level, vector<int> &buffer, vector<vector<int>> &ret){
        if(buffer.size()==len){
            ret.push_back(buffer);
            return;
        }
        for(int i=cur_level; i<=range; ++i){
            buffer.push_back(i);
            helper(range, len, i+1, buffer, ret);
            buffer.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ret;
        vector<int>temp;
        helper(n, k, 1, temp, ret);
        return ret;
    }
};