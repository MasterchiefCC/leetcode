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