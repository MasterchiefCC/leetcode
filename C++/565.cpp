#include "mod.h"
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ret=INT_MIN;
        int len=nums.size();
        for(int a=0; a<len; a++){
            int index=a;
            int size=0;
            while(nums[index]>=0){
                int temp=nums[index];
                nums[index]=-1;
                index=temp;
                size++;
            }
            ret=max(ret, size);
        }
        return ret;
    }
};