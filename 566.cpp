#include"mod.h"
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int tot_num=r*c;
        int cur_num=nums.size()*nums[0].size();
        if(tot_num!=cur_num)return nums;
        vector<vector<int>>ret(r, vector<int>(c, 0));
        int ret_x=0, ret_y=0;
        for(int x=0; x<nums.size(); x++){
          for(int y=0; y<nums[x].size(); y++){
            ret[ret_x][ret_y]=nums[x][y];
            ++ret_y;
            if(ret_y>=c){
              ret_y=0;
              ++ret_x;
            }
          }
        }
      return ret;
    }
};