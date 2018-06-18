#include "mod.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1, left=0, ret=INT_MIN;
        while(left<right){
            ret=max(ret, min(height[right], height[left])*(right-left));
            if(height[left]<height[right])++left;
            else --right;
        }
        return ret;
    }
};