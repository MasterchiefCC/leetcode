#include "mod.h"
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs){
                                            if(lhs.size()==rhs.size())return lhs>rhs;
                                            return lhs.size()>rhs.size();});
        unordered_set<string>m_set;
        for(int i=0; i<strs.size(); ++i){
            if(i==strs.size()-1||strs[i]!=strs[i+1]){
                bool lock=true;
                for(const string& mem: m_set){
                    if(is_substr(mem, strs[i])){
                        lock=false;
                        break;
                    }
                }
                if(lock)return strs[i].size();
            }
            m_set.insert(strs[i]);
        }
        return -1;
    }
private:
    inline bool is_substr(const string& str, const string& sub){
        int i=0;
        for(const char& c:str){
            if(sub[i]==c)++i;
            if(i==sub.size())break;
        }
        return i==sub.size();
    }
};