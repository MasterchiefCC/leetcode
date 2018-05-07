#include "mod.h"
class Solution {
    vector<int>buffer;
public:
    Solution(vector<int> nums):buffer(nums) {}
    
    int pick(int target) {
        srand((unsigned)time(NULL));
        int ret, cnt=0;
        for(int i=0; i<buffer.size(); ++i){
            if(buffer[i]==target){
                if(rand()%cnt==0)ret=buffer[i];
            }
        }
        return ret;
    }
};