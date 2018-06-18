#include"mod.h"
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len=A.size();
        vector<vector<int>>m_map(2*len+1, vector<int>(2*len+1, 0));
        for(int i_A=0; i_A<len; ++i_A)
            for(int j_A=0; j_A<len; ++j_A)
                if(A[i_A][j_A]==1)
                    for(int i_B=0; i_B<len; ++i_B)
                        for(int j_B=0; j_B<len; ++j_B)
                            if(B[i_B][j_B]==1)++m_map[i_A-i_B+len][j_A-j_B+len];
        
        int ret=0;
        for(int i=0; i<m_map.size(); ++i)
            for(int j=0; j<m_map[i].size(); ++j)
                ret=max(ret, m_map[i][j]);
                    
        return ret;
    }
};