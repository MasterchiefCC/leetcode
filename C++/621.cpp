#include"mod.h"

class Solution {
    static bool cmp(const pair<char, int>&p1, const pair<char, int>&p2){
        return p1.second>p2.second;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty())return 0;
        sort(tasks.begin(), tasks.end());
        vector<pair<char, int>>m_arr(1, make_pair(tasks[0],0));
        int index=0;
        for(char &task : tasks){
            if(task!=m_arr.back().first){
                m_arr.push_back(make_pair(task, 1));
            }
            else{
                ++m_arr.back().second;
            }
        }
        int ret=0;
        sort(m_arr.begin(), m_arr.end(), cmp);
        while(!m_arr.empty()){
            int interval=n+1;
            int index=0;
            while(interval--){
                if(index>=m_arr.size()){
                    ret+=interval;
                    break;
                }
                --m_arr[index].second;
                if(m_arr[index].second==0){
                    m_arr.erase(m_arr.begin()+index);
                    --index;
                }
                ++ret;
                ++index;
            }
            sort(m_arr.begin(), m_arr.end(), cmp);    
        }
        return ret;
    }
};