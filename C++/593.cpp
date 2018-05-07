#include"mod.h"
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int>m_set{distance_square(p1, p2),distance_square(p1, p3), distance_square(p1, p4),\
                      distance_square(p2, p3), distance_square(p2, p4), distance_square(p3, p4)};
        return !m_set.count(0)&&m_set.size()==2;
    }
    int distance_square(const vector<int> &p1, const vector<int> &p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
};