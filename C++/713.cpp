#include "mod.h"
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int ret=0, left=0, val=1;
        for(int right=0; right<nums.size(); ++right){
            val*=nums[right];
            while(val>=k)val/=nums[left++];
            ret+=right-left+1;
        }
        return ret;
    }
};

int main(){
    vector<int>in={10,2,2,5,4,4,4,3,7,7};
    Solution test;
    cout<<test.numSubarrayProductLessThanK(in, 289)<<endl;
    return 0;
}