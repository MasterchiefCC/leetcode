#include "mod.h"
class Solution {
private:
    bool isPalindrome(string s){
        int len=s.size();
        int half_len=len/2;
        for(int a=0; a<half_len; a++){
            if(s[a]!=s[len-1-a]){
                return false;
            }
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int len=1;
        int cnt=0;
        int size=s.size();
        while(1){
            auto it_begin=s.begin();
            while(1){
                auto it_end=it_begin+(len-1);
                string temp(it_begin, it_end);
                cnt=isPalindrome(temp)?cnt+1:cnt;
                if(it_end==s.end())break;
                it_begin++;
            }
            len++;
            if(len>size)break;
        }
            return cnt;
    }
};