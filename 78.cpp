class Solution {
    vector<vector<int>>result;
    int len;
    void helper(const vector<int>&nums, vector<int>temp, int level){
        for(int i=level; i<len; ++i){
            temp.push_back(nums[i]);
            result.push_back(temp);
            helper(nums, temp, i+1);
            temp.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        len=nums.size();
        vector<int>temp;
        helper(nums, temp, 0);
        result.push_back(vector<int>(0));
        return result;
    }
};