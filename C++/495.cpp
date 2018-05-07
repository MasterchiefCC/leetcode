#include "mod.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len=timeSeries.size();
        int ret=0;
        if(len<1)return 0;
        int point=timeSeries[0];
        for(int a=0; a<len; a++){
            int cur_point=timeSeries[a]+duration;
            ret+=timeSeries[a]>point?duration:cur_point-point;
            point=cur_point;
        }
        return ret;
    }
};