#include "mod.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>m_map(numCourses);
        for(const pair<int, int>requist:prerequisites)m_map[requist.second].push_back(requist.first);
        
        //0->unknown 1->visited 2->visiting;
        vector<int>stats(numCourses, 0);
        
        for(int i=0; i<numCourses; ++i)if(!dfs(m_map, stats, i))return false;
        return true;
    }
private:
    bool dfs(const vector<vector<int>>&m_map, vector<int>& stats, int cur){
        if(stats[cur]==1)return true;
        if(stats[cur]==2)return false;
        
        stats[cur]=2;
        for(const int& next:m_map[cur])if(!dfs(m_map, stats, next))return false;
        stats[cur]=1;
        
        return true;
    }
};