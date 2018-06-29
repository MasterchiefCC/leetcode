#include "mod.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, ret_first=-1, ret_second=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target&&(mid+1>=nums.size()||nums[mid]<nums[mid+1])){
                ret_second=mid;
                break;
            }
            
            else if(target<nums[mid])right=mid-1;
            else left=mid+1;
        }
        
        if(ret_second==-1)return {-1, -1};
        
        left=0,right=ret_second;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target&&(mid-1<0||nums[mid-1]<nums[mid])){
                ret_first=mid;
                break;
            }
            else if(nums[mid]==target)right=mid-1;
            else left=mid+1;
        }
        
        return {ret_first, ret_second};
    }
};

int main(){
    vector<int>in={5,7,7,8,8,8,8,8,8,8,8,8,8,8,8,10};
    Solution test;
    vector<int>ret=test.searchRange(in, 8);
    cout<<ret[0]<<ret[1]<<endl;
}