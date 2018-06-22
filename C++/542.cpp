#include "mod.h"
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())return matrix;
        vector<int>moves={0,1,0,-1,1,0,-1,0};
        vector<vector<int>>ret{matrix.size(), vector<int>(matrix[0].size(), INT_MAX)};
        
        queue<pair<int, int>>m_queue;
        for(int i=0; i<matrix.size(); ++i)
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j]!=0)continue;
                m_queue.push(make_pair(i, j));
                ret[i][j]=0;
        }
        
        while(!m_queue.empty()){
            int cur_i=m_queue.front().first, cur_j=m_queue.front().second;
            m_queue.pop();
            for(int move=0; move<moves.size()-1; move+=2){
                int temp_i=cur_i+moves[move], temp_j=cur_j+moves[move+1];
                
                if(temp_i<0||temp_j<0||temp_i>=ret.size()||temp_j>=ret[temp_i].size()||\
                   ret[temp_i][temp_j]<=ret[cur_i][cur_j]+1)continue;
                
                ret[temp_i][temp_j]=ret[cur_i][cur_j]+1;
                m_queue.push(make_pair(temp_i, temp_j));
            }  
        }
        return ret;
    }
};
