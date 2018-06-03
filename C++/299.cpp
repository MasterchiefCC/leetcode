#include "mod.h"
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0, cow=0;
        vector<int>m_map(128, 0);
        for(int i=0; i<secret.size(); ++i){
            if(secret[i]==guess[i])++bull;
            ++m_map[secret[i]];
        }
        
        for(const char& c:guess){
            if(m_map[c]-->0)cow++;
        }
        cow-=bull;
        return to_string(bull)+"A"+to_string(cow)+"B";
        
    }
};