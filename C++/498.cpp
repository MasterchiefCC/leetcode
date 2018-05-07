#include"mod.h"

class Solution{
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        bool sw=0;
        int x=0, y=0;
        vector<int>ret;
        int x_len=matrix.size();
        if(x_len==0)return ret;
        int y_len=matrix[0].size();
        ret.push_back(matrix[0][0]);
        while(1){
            if(sw==0){
                --x, ++y;
                if(x==-1){
                    ++x;
                    sw=1;
                }
                if(x<x_len&&y<y_len)ret.push_back(matrix[x][y]);
            }
            else if(sw==1){
                ++x, --y;
                if(y==-1){
                    ++y;
                    sw=0;
                }
                if(x<x_len&&y<y_len)ret.push_back(matrix[x][y]);
            }
            if(x>=x_len-1&&y>=y_len-1)break;
        }
        return ret;
    }
};