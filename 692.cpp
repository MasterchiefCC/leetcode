#include "mod.h"
class Solution {
    static bool cmp(const pair<string, int> &P1, const pair<string, int> &P2){
        if(P1.second==P2.second)return P1.first<P2.first;
        return P1.second>P2.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ret;
        if(words.empty())return ret;
        map<string, int>m_map;
        for(int i=0; i<words.size(); ++i)++m_map[words[i]];
        
        vector<pair<string, int>>buffer;
        for(auto it=m_map.begin(); it!=m_map.end(); ++it)buffer.push_back(make_pair(it->first, it->second));
        
        sort(buffer.begin(), buffer.end(), cmp);
        for(int i=0; i<k; ++i)ret.push_back(buffer[i].first);
        
        return ret;
    }
};