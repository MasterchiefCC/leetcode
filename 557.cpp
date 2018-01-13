#include "mod.h"
 
class Solution {
public:
    string reverseWords(string s) {
        auto bit=s.begin();
        for(auto it=s.begin(); it!=s.end(); it++){
            if(*it==' '){
                reverse(bit, it);
                bit=it+1;
            }
        }
        reverse(bit, s.end());
        return s;
    }
};