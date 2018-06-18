#include "mod.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())return;
        set<int>row, col;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto it=row.begin(); it!=row.end(); ++it){
            for(int i=0; i<matrix[*it].size(); ++i)
                matrix[*it][i]=0;
        }
        for(auto it=col.begin(); it!=col.end(); ++it){
            for(int i=0; i<matrix.size(); ++i)
                matrix[i][*it]=0;
        }
    }
};