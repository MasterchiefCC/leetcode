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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        map<int, int>m_map;
        for(const Interval& interval: intervals){
            auto it=m_map.lower_bound(interval.start);
            if(it==m_map.end())m_map[interval.end]=interval.start;
            else{
                int start=min(it->second, interval.start);
                int end=max(it->first, interval.end);
                m_map.erase(it);
                m_map[end]=start;
            }
        }
        vector<Interval>ret;
        for(const pair<int, int>& temp: m_map)ret.push_back(Interval(temp.second, temp.first));
        return ret;
    }
private:
    static bool cmp(const Interval& lhs, const Interval& rhs){
        return lhs.start<rhs.start;
    }
};