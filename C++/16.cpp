#include "mod.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret=-1, diff=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int base=0; base<nums.size()-2; ++base){
            int left=base+1, right=nums.size()-1;
            while(left<right){
                int cur=nums[base]+nums[left]+nums[right];
                int cur_diff=cur-target;
                if(cur_diff==0)return target;
                if(abs(cur_diff)<diff){
                    diff=abs(cur_diff);
                    ret=cur;
                }
                if(cur_diff<0)++left;
                else --right;
            }
        }
        return ret;
    }
};

int main(){
    vector<int>in={-1, 2, 1, -4};
    Solution test;
    cout<<test.threeSumClosest(in, 1);
}