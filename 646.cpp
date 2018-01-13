#include "mod.h"

class Solution {
    static bool comp(vector<int>p1, vector<int>p2){
        return p1[1]<p2[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int len=pairs.size();
        int ret=0;
        int last=INT_MIN;
        for(int a=0; a<len; a++){
            last=(last<pairs[a][0]?(ret++, pairs[a][1]):last);
        }
        return ret;
    }
};