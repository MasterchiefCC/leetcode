#include "mod.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int>m_map;
        vector<vector<string>>ret;
        for(const string &str:strs){
            string temp=str;
            sort(temp.begin(), temp.end());
            if(m_map.find(temp)==m_map.end()){
                int len=ret.size();
                m_map[temp]=len;
                ret.resize(len+1);
                ret[len].push_back(str);
            }
            else ret[m_map[temp]].push_back(str);
        }
        return ret;
    }
};