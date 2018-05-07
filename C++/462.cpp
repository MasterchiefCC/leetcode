#include "mod.h"
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(), nums.end());
        int moves=0;
        int mid_index=len/2,  mid=nums[mid_index];
        for(int a=0;a<len; a++){
            if(a==mid_index)continue;
            else moves+=abs(nums[a]-mid);
        }
        if(len%2==1)return moves;
        else{
            int moves_even=0;
            mid_index=(len-1)/2, mid=nums[mid_index];
            for(int a=0; a<len; a++){
                if(a==mid_index)continue;
                else moves_even+=abs(nums[a]-mid);
            }
            return min(moves, moves_even);
        }
    }
};