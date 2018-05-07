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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int>m_map;
        for(int i=0; i<intervals.size(); ++i){
            m_map[intervals[i].start]=i;
        }
        vector<int>ret(intervals.size(), -1);
        for(int i=0; i<intervals.size(); ++i){
            auto it = m_map.lower_bound(intervals[i].end);
            if(it==m_map.end())continue;
            ret[i]=it->second;
        }
        return ret;
    }
};

//lower_bound 返回<=key的最大的iterator;
//upper_bound返回第一个>key的iterator