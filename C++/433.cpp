#include "mod.h"
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>bank_set(bank.begin(), bank.end());
        
        if(bank_set.find(end)==bank_set.end())return -1;
        
        unordered_set<string>visited{start};
        
        queue<string>m_queue;
        m_queue.push(start);
        int ret=0;
        while(!m_queue.empty()){
            int len=m_queue.size();
            for(int i=0; i<len; ++i){
                string temp=m_queue.front();
                m_queue.pop();
                if(is_different(temp, end, bank_set, m_queue, visited))return ret;
            }
            ++ret;
        }
        return -1;
    }
private:
    inline bool is_different(const string& cur, const string& end, \
                            const unordered_set<string>& bank_set,\
                             queue<string>& m_queue, unordered_set<string>& visited){
        if(cur==end)return true;
        for(int i=0; i<cur.size(); ++i){
            string temp=cur;
            temp[i]='A';
            set_insert(temp, bank_set, m_queue, visited);
            
            temp[i]='C';
            set_insert(temp, bank_set, m_queue, visited);
            
            temp[i]='G';
            set_insert(temp, bank_set, m_queue, visited);
            
            temp[i]='T';
            set_insert(temp, bank_set, m_queue, visited);
        }
        return false;
    }
    inline void set_insert(const string& cur, const unordered_set<string>& bank_set,\
                             queue<string>& m_queue, unordered_set<string>& visited){
        if(bank_set.find(cur)!=bank_set.end()&&visited.find(cur)==visited.end()){
            visited.insert(cur);
            m_queue.push(cur);
        }
    }
};