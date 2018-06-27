#include "mod.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>path;
        for(const string& word: wordDict)path[word]=true;
        return wordBreak(s, path);
    }
private:
    bool wordBreak(const string& s, unordered_map<string, bool>& m_map){
        if(m_map.find(s)!=m_map.end())return m_map[s];
        
        
        for(int i=1; i<s.size(); ++i){
            auto it=m_map.find(s.substr(i));
            
            if(it!=m_map.end()&& it->second&& wordBreak(s.substr(0, i), m_map))return m_map[s]=true;
            
        }
        return m_map[s]=false;
    }
};

int main(){
    string s="leetcode";
    vector<string>in={"leet","code"};
    Solution test;
    cout<<test.wordBreak(s, in);
    return 0;
}