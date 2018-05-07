#inclde "mod.h"
class Solution {
    vector<vector<int>>result;
    void helper(vector<int> temp, const int& k, int cur_val, int level){
        int len=temp.size();
        if(cur_val<0||len>k)return;
        if(cur_val==0&&len==k)result.push_back(temp);
        for(int num=level; num<=9; ++num){
            temp.push_back(num);
            helper(temp, k, cur_val-num, num+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        vector<int>temp;
        helper(temp, k, n, 1);
        return result;    
    }
};