#include "mod.h"
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret=0;
        for(const string& word:words){
            if(is_stretchy(S, word))++ret;
        }
        return ret;
    }
private:
    inline bool is_stretchy(const string& S, const string& word){
        if(S.size()<word.size())return false;
        int i=0, j=0;
        while(i<S.size()&&j<word.size()){
            if(S[i]!=word[j])return false;
            int cnt_i=1, cnt_j=1;
            while(++i<S.size()&&S[i]==S[i-1])++cnt_i;
            while(++j<word.size()&&word[j]==word[j-1])++cnt_j;
            if(cnt_i<cnt_j||cnt_i<3&&cnt_i!=cnt_j)return false;
        }
        return i==S.size()&&j==word.size();
    }
};