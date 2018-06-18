#include "mod.h"
class Solution {
private:
    int helper(int p, int max_val, vector<bool> buffer){
        int ret=0;
        if(p>max_val){
            return 1;
        }
        for(int a=1; a<=max_val; a++){
            if(!buffer[a]&&(a%p==0||p%a==0)){
                buffer[a]=1;
                ret+=helper(p+1, max_val, buffer);
                buffer[a]=0;
            }
        }
        return ret;
    }
public:
    int countArrangement(int N) {
        vector<bool> buffer(N+1, 0);

        int ret=helper(1, N, buffer);
        return ret;
    }
};

int main(){
    Solution a;
    int cnt=a.countArrangement(2);

    return 0;
}