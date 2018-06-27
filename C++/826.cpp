#include "mod.h"
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>buffer(profit.size());
        for(int i=0; i<profit.size(); ++i){
            buffer[i].first=profit[i];
            buffer[i].second=difficulty[i];
        }
        sort(buffer.begin(), buffer.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
            if(lhs.first==rhs.first)return lhs.second<rhs.second;
            return lhs.first>rhs.first;
        });
        sort(worker.begin(), worker.end(), greater<int>());
        int ret=0;
        int i=0;
        for(const pair<int, int>& cur: buffer){
            while(i<worker.size()&&worker[i]>=cur.second){
                ret+=cur.first;
                ++i;            
            }
            if(i==worker.size())break;
        }
        return ret;
    }
};