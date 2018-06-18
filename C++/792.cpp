#include "mod.h"
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>>buffer(26);
        for(int i=0; i<S.size(); ++i)buffer[S[i]-'a'].push_back(i);
        unordered_map<string, bool>used;
        
        int ret=0;
        for(const string& word:words){
            ret+=is_match(buffer, used, word);
        }
        
        return ret;
    }
private:
    inline bool is_match(const vector<vector<int>>& buffer, unordered_map<string, bool>& used, const string& S){
        if(used.count(S))return used[S];
        
        int last=-1;
        for(const char& c:S){
            const vector<int>& temp=buffer[c-'a'];
            const auto it=std::lower_bound(temp.begin(), temp.end(), last+1);
            if(it==temp.end())return used[S]=false;
            last=*it;
        }
        return used[S]=true;
    }
};