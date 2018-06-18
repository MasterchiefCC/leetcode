#include "mod.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        std::map<char, char>buffer;
        std::vector<int>used(256, false);
        for(int i=0; i<s.size(); ++i){
            auto it=buffer.find(s[i]);
            if(it!=buffer.end()&&it->second!=t[i]||it==buffer.end()&&used[t[i]])return false;
            buffer[s[i]]=t[i];
            used[t[i]]=true;
            s[i]=buffer[s[i]];
        }
        
        return s==t;
    }
};