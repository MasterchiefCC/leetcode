#include "mod.h"
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>m_stack;
        for(const int &temp: asteroids){
            if(m_stack.empty())m_stack.push_back(temp);
            
            else if(m_stack.back()>0&&temp<0){
                bool ok=true;
                while(!m_stack.empty()&&m_stack.back()>0&&ok){
                    if(m_stack.back()==abs(temp)){
                        m_stack.pop_back();
                        ok=false;
                    }
                    else if(m_stack.back()>abs(temp))ok=false;
                    else m_stack.pop_back();
                }
                if(ok)m_stack.push_back(temp);
            }
            
            else m_stack.push_back(temp);
        }
        return m_stack;
    }
};