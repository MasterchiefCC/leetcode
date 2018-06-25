#include "mod.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())return false;
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[left]==nums[mid])++left;
            if(nums[mid]==target)return true;
            else if(nums[left]<nums[mid]){
                if(nums[left]<=target&&target<nums[mid])right=mid-1;
                else left=mid+1;
            }
            else {
                if(nums[mid]<target&&target<=nums[right])left=mid+1;
                else right=mid-1;
            }
        }
        return false;
    }
};
int main(){
    vector<int>in={3,1};
    Solution test;
    cout<<test.search(in, 1)<<endl;
    return 0;
}