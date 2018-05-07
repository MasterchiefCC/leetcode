#include "mod.h"
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger>m_stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1; i>=0; --i){
            m_stack.push(nestedList[i]);
        }
    }

    int next() {
        int ret=m_stack.top().getInteger();
        m_stack.pop();
        return ret;
    }

    bool hasNext() {
        while(!m_stack.empty()){
            if(m_stack.top().isInteger())return true;
            NestedInteger temp=m_stack.top();
            m_stack.pop();
            const vector<NestedInteger> t_array=temp.getList();
            for(int i=t_array.size()-1; i>=0; --i)
                m_stack.push(t_array[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */