#include "mod.h"

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(), points.end());
        int ret=1, end=points[0].second;
        for(int i=1; i<points.size(); ++i){
            if(points[i].first<=end){
                end=min(end, points[i].second);
            }
            else{
                ++ret;
                end=points[i].second;
            }
        }
        return ret;
    }
};