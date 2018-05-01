#include "mod.h"
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty())return 0;
        
        sort(intervals.begin(), intervals.end(), [](const Interval &C1, const Interval&C2){return C1.start<C2.start;});
        
        int ret=0, cur_end=intervals[0].end;
        for(int i=1; i<intervals.size(); ++i){
            int temp=cur_end>intervals[i].start?1:0;
            cur_end=temp==1?min(cur_end,intervals[i].end):intervals[i].end;
            ret+=temp;
        }
        return ret;
    }
};