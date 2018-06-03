#include"mod.h"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0;
        vector<int> buffer(128, 0);
        for (const char& c : s1) ++buffer[c];
        for (int right = 0; right < s2.size(); ++right) {
            if (--buffer[s2[right]] < 0) {
                while (++buffer[s2[left++]] != 0) {}
            } else if (right - left + 1 == s1.size()) return true;
        }
        return s1.size() == 0;
    }
};