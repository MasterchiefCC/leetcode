#include "mod.h"
class ExamRoom {
public:
    ExamRoom(int N):size(N){
    
    }
    
    int seat() {
        if(m_map.size()==0){
            m_map.insert(0);
            return 0;
        }
        if(m_map.size()==1){
            auto it=m_map.begin();
            int ret=*it-0>size-1-*it?0:size-1;
            m_map.insert(ret);
            return ret;
        }
        auto it=m_map.begin();
        int dist=-1, ret=-1, lower, upper, last=*it==0?-1:-(*it);
        while(it!=m_map.end()){
            int cur_dist=*it-last;
            if(cur_dist>dist){
                int pos=last+(*it-last)/2;
                if(dist==-1)change(ret, dist, lower, upper, pos, cur_dist, last, *it);
                else{
                    int last_dist=min(ret-lower, upper-lower);
                    int cur_dist=min(pos-last, *it-pos);
                    if(last_dist>=cur_dist){
                        last=*it;
                        ++it;
                        continue;
                    }
                    change(ret, dist, lower, upper, pos, cur_dist, last, *it);
                }
            }
            last=*it;
            ++it;
        }
        if(ret==-1)ret=m_map.size();
        m_map.insert(ret);
        return ret;
    }
    
    void leave(int p) {
        m_map.erase(p);
    }
private:
    set<int>m_map;
    int size;
    inline void change(int &ret, int &dist, int& lower, int& upper, \
    int pos, int cur_dist, int last, int up){
        ret=pos;
        dist=cur_dist;
        lower=last;
        upper=up;
    }
};