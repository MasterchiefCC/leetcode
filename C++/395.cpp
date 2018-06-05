#include "mod.h"
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret=0, start=0;
        while(start+k<=s.size()){
            int nxt_s=start, mask=0;
            vector<int>cnt(26, 0);
            for(int i=start; i<s.size(); ++i){
                int temp=s[i]-'a';
                if(++cnt[temp]<k)mask|=1<<temp;
                else mask&=(~(1<<temp));
                if(mask==0){
                    ret=max(ret, i-start+1);
                    nxt_s=i;
                }
            }
            start=nxt_s+1;
        }
        return ret;
    }
};