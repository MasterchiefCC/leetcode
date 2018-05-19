#include "mod.h"
class Solution_sort {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0)return false;
        vector<int>buffer(k, 0);
        sort(nums.begin(), nums.end());
        if(helper(nums, buffer, nums.size()-1, sum/k))return true;
        return false;
    }
private:
    bool helper(const vector<int>&nums, vector<int>&buffer, int idx, const int &target){
        if(idx==-1){
            for(int i=0; i<buffer.size(); ++i){
                if(buffer[i]!=target)return false;
            }
            return true;
        }
        const int &num=nums[idx];
        for(int i=0; i<buffer.size(); ++i){
            if(buffer[i]+num>target)continue;
            buffer[i]+=num;
            if(helper(nums, buffer, idx-1, target))return true;
            buffer[i]-=num;
        }
        return false;
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0)return false;
        vector<int>buffer(k, 0);
        sort(nums.begin(), nums.end());
        if(helper(nums, buffer, nums.size()-1, sum/k))return true;
        return false;
    }
private:
    bool helper(const vector<int>&nums, vector<int>&buffer, int idx, const int &target){
        if(idx==-1){
            for(int i=0; i<buffer.size(); ++i){
                if(buffer[i]!=target)return false;
            }
            return true;
        }
        const int &num=nums[idx];
        for(int i=0; i<buffer.size(); ++i){
            if(buffer[i]+num>target)continue;
            buffer[i]+=num;
            if(helper(nums, buffer, idx-1, target))return true;
            buffer[i]-=num;
        }
        return false;
    }
};