#include "mod.h"
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.empty())return -1;
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<nums[right]){
                if(nums[mid]<target&&target<=nums[right])left=mid+1;
                else right=mid-1;
            }
            else{
                if(nums[left]<=target&&target<nums[mid])right=mid-1;
                else left=mid+1;
            }
        }
        return -1;
    }
};

main() {
  // vector<int>in={4,5,6,7,8,1,2,3};
  vector<int> in = {3,1};
  Solution test;
  // for(int i=1; i<9; ++i)cout<<test.search(in, i)<<endl;
  cout<<test.search(in, 1);
  return 0;
}