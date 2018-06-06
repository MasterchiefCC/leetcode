#include "mod.h"
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<map<int, int>>m_map(N+1);
        for(const vector<int>& time: times){
            const int& source=time[0];
            const int& target=time[1];
            const int& dis=time[2];
            m_map[source][target]=dis;
        }
        
        vector<int>buffer(N+1, INT_MAX);
        
        auto cmp=[](const edges& lhs, const edges& rhs){return lhs.dist>rhs.dist;};
        priority_queue<pair<int, int>, vector<edges>, decltype(cmp)>m_pq(cmp);
        
        m_pq.push(edges(K, 0));
        
        while(!m_pq.empty()){
            int target=m_pq.top().target;
            int dist=m_pq.top().dist;
            m_pq.pop();
            if(dist>=buffer[target])continue;
            buffer[target]=dist;
            for(auto it:m_map[target]){
                int temp_dist=dist+it.second;
                if(temp_dist<buffer[it.first])m_pq.push(edges(it.first, temp_dist));
            }
            
        }
        int ret=INT_MIN;
        for(int i=1; i<buffer.size(); ++i){
            if(buffer[i]==INT_MAX)return -1;
            ret=max(ret, buffer[i]);
        }
        return ret;
    }
private:
    struct edges{
        int target, dist;
        edges(const int& target, const int& dist):target(target), dist(dist){}
    };
};