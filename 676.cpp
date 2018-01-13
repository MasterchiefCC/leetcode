#include "mod.h"
class MagicDictionary {
    bool isMatch(string s1, string s2){
        int cnt=0;
        if(s1.size()!=s2.size())return false;
        int len=s1.size();
        for(int a=0; a<len; a++){
            cnt+=(s1[a]!=s2[a]?1:0);
            if(cnt>1)return false;
        }
        return cnt==1;
    }
    vector<string>buffer;
public:
    MagicDictionary() {
        
    }

    void buildDict(vector<string> dict) {
        buffer=dict;
    }
    
    bool search(string word) {
        int len=buffer.size();
        for(int a=0; a<len; a++){
            if(isMatch(word, buffer[a]))return true;
        }
        return false;
    }
};