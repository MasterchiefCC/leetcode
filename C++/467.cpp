#include "mod.h"
class Solution {
public:
    int findSubstringInWraproundString(string p){
        vector<int>alphabet(26, 0);
        int len=0, ret=0;
        for(int i=0; i<p.size(); ++i){
            if(i>0&&(p[i]-1==p[i-1]||p[i-1]-p[i]==25))++len;
            else len=1;
            if(len>alphabet[p[i]-'a']){
                ret+=len-alphabet[p[i]-'a'];
                alphabet[p[i]-'a']=len;
            }
        }
        return ret;
    }
};
int main(){
    Solution test;
    cout<<test.findSubstringInWraproundString("cac")<<endl;
    return 0;
}