#include "mod.h"
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int cnt=0;
        vector<int>buffer(shifts.size(), 0);
        for(int i=0; i<shifts.size(); ++i){
            buffer[i]=shifts[i]%26;
            cnt+=buffer[i];
        }
        
        for(int i=0; i<buffer.size(); ++i){
            unsigned char temp=S[i]+cnt%26;
            S[i]=temp>'z'?temp-'z'+'a'-1:temp;
            cnt-=buffer[i];
        }
        return S;
    }
};