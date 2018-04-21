#include "mod.h"

class MyCalendar {
    map<int, int>m_map;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=m_map.lower_bound(start);
        if(it!=m_map.end()&&it->first<end)
            return false;
        if(it!=m_map.end()&&(--it)->second>start)
            return false;
        m_map[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */