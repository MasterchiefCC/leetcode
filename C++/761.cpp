#include "mod.h"
class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt=0, start=0;
        vector<string>buffer;
        for(int i=0; i<S.size(); ++i){
            if(S[i]=='1')++cnt;
            else --cnt;
            
            if(cnt==0){
                buffer.push_back("1"+makeLargestSpecial(S.substr(start+1, i-start-1))+"0");
                start=i+1;
            }
        }
        sort(buffer.begin(), buffer.end(), greater<string>());
        
        string ret;
        for(const string& s: buffer)ret+=s;
        
        return ret;
    }
    
};