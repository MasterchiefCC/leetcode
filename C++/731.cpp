#include "mod.h"
class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        ++m_map[start];
        --m_map[end];
        int cnt=0;
        for(auto it =m_map.begin(); it!=m_map.end(); ++it){
            cnt+=it->second;
            if(cnt==3){
                --m_map[start];
                ++m_map[end];
                return false;
            }
            if(it->second>end)break;
        }
        
        return true;
    }
private:
    map<int, int>m_map;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */