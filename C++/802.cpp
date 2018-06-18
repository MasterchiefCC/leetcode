#include"mod.h"
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<States>state(graph.size(), UNKNOWN);
        vector<int>ret;
        for(int i=0; i<graph.size(); ++i)if(dfs(graph, i, state)==SAFE)ret.push_back(i);
        std::sort(ret.begin(), ret.end());
        return ret;
    }
private:
    enum States{UNKNOWN, SAFE, UNSAFE, VISITED};
    
    States dfs(const vector<vector<int>>& graph, int cur, vector<States>& state){
        if(state[cur]==VISITED)return state[cur]=UNSAFE;
        if(state[cur]==SAFE||state[cur]==UNSAFE)return state[cur];
        state[cur]=VISITED;
        for (const int& next:graph[cur]){
            if(dfs(graph, next, state)==UNSAFE)return state[cur]=UNSAFE;
        }
        return state[cur]=SAFE;
    }
};