#include "mod.h"
class Solution {
    vector<vector<int>>result;
    void helper(const vector<int>&nums, set<int>used, vector<int>buffer){
        int len=nums.size();
        if(buffer.size()==len){
            result.push_back(buffer);
            return;
        }
        for(int i=0; i<len; i++){
            if(used.find(nums[i])==used.end()){
                buffer.push_back(nums[i]);
                used.insert(nums[i]);
                helper(nums, used, buffer);
                buffer.pop_back();
                used.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        vector<int>tempV;
        set<int>tempU;
        helper(nums, tempU, tempV);
        return result;
    }
};