class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==t)return true;
        int pos_s=0, pos_t=0, len_s=s.size(),len_t=t.size();
        while(pos_t<len_t){
            if(s[pos_s]==t[pos_t++])++pos_s;
            if(pos_s==len_s)return true;
        }
        return false;
    }
};