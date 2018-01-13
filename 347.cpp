#include "mod.h"
class Solution {
    static bool comp(pair<int, int>p1, pair<int, int>p2){
        return p1.second>p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mm;
        int len=nums.size();
        for(int a=0; a<len; a++){
            map<int, int>::iterator mit=mm.find(nums[a]);
            mit==mm.end()?mm[nums[a]]=1:mit->second++;
        }
        vector<pair<int, int>> buffer;
        for(map<int, int>::iterator mit=mm.begin(); mit!=mm.end(); mit++){
            buffer.push_back(make_pair(mit->first, mit->second));
        }
        sort(buffer.begin(), buffer.end(), comp);
        vector<int>ret;
        for(int a=0; a<k; a++){
            ret.push_back(buffer[a].first);
        }
        return ret;
    }
};