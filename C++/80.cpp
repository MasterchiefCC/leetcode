#include "mod.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=INT_MIN, cur_cnt=0;
        for(auto it= nums.begin(); it!=nums.end();){
            if(cur!=*it){
                cur=*it;
                cur_cnt=1;
                ++it;
            }
            else if(cur==*it&&cur_cnt==1){
                ++cur_cnt;
                ++it;
            }
            else {
                it=nums.erase(it);
            }
        }
        return nums.size();
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=INT_MIN, cur_cnt=0, j=0;
        for(int i=0; i<nums.size(); ++i){
            if(cur!=nums[i]){
                cur=nums[i];
                cur_cnt=1;
                nums[i-j]=nums[i];
            }
            else if(cur==nums[i]&&cur_cnt==1){
                ++cur_cnt;
                nums[i-j]=nums[i];
            }
            else ++j;
        }
        nums.resize(nums.size()-j);
        return nums.size();
    }
};