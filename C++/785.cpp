#include "mod.h"
class Solution_BFS {//BFS
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size(), 0);
        
        for(int i=0; i<graph.size(); ++i){
            if(colors[i]!=0)continue;
            queue<int>m_queue;
            m_queue.push(i);
            colors[i]=1;
            
            while(!m_queue.empty()){
                int cur=m_queue.front();
                m_queue.pop();
                for(const int &next :graph[cur]){
                    if(colors[next]==0){
                        colors[next]=-1*colors[cur];
                        m_queue.push(next);
                    }
                    else if (colors[next]==colors[cur])return false;
                }
            }
        }
        return true;
    }
};

class Solution_DFS {//DFS
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size(), 0);
        
        for(int i=0; i<graph.size(); ++i){
            if(colors[i]==0&&!helper(graph, colors, i, 1))return false;
        }
        return true;
    }
private:
    bool helper(const vector<vector<int>>& graph, vector<int> &colors, int cur, int color){
        if(colors[cur]!=0)return colors[cur]==color;
        colors[cur]=color;
        for(const int &next:graph[cur]){
            if(!helper(graph, colors, next, color*-1))return false;
        }
        return true;
    }
};