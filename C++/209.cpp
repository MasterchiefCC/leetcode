#include "mod.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0, cnt=0, ret=INT_MAX;
        for(int right=0; right<nums.size(); ++right){
            cnt+=nums[right];
            if(cnt>=s){
                ret=min(ret, right-left+1);
                while(cnt>=s&&left<=right){
                    ret=min(ret, right-left+1);
                    cnt-=nums[left];
                    ++left;
                }
            }
        }
        return ret==INT_MAX?0:ret;
    }
};
int main(){
    vector<int>in={2,3,1,2,4,3};
    Solution test;
    cout<<test.minSubArrayLen(7, in);
}