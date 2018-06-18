#include"mod.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ret;
        vector<string>cur;
        dfs(s, ret, cur, 0);
        return ret;
    }
private:
    inline bool is_palindrome(const string& s, int start, int end){
        while(start<end&&s[start]==s[end]){
            ++start;
            --end;
        }
        return start>=end;
    }
    
    void dfs(const string& s, vector<vector<string>>& ret, vector<string>& cur, int begin){
        if(begin>=s.size()){
            ret.push_back(cur);
            return;
        }
        
        for(int i=begin; i<s.size(); ++i){
            if(is_palindrome(s, begin, i)){
                cur.push_back(s.substr(begin, i-begin+1));
                dfs(s, ret, cur, i+1);
                cur.pop_back();
            }
        }
    }
};