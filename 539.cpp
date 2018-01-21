#include "mod.h"
class Solution {
	static bool mySort(const pair<int, int> &p1, const pair<int, int> &p2) {
		if (p1.first == p2.first)return p1.second < p2.second;
		return p1.first < p2.first;
	}
public:
	int findMinDifference(vector<string>& timePoints) {
		int len = timePoints.size();
		vector<pair<int, int>> buffer(len, pair<int, int>(-1, -1));
		for (int i = 0; i < len; i++) {
			buffer[i].first = stoi(timePoints[i].substr(0, 2));
			buffer[i].second = stoi(timePoints[i].substr(3, 2));
		}
		sort(buffer.begin(), buffer.end(), mySort);
		int ret = INT_MAX;
		for (int i = 1; i <len; ++i) {
            ret=min(ret, 60*(buffer[i].first-buffer[i-1].first)+(buffer[i].second-buffer[i-1].second));
		}
        int h_diff=buffer[0].first-buffer[len-1].first, m_diff=buffer[0].second-buffer[len-1].second;
        ret=min(ret,(m_diff<0?(--h_diff, 60+m_diff):m_diff)+(h_diff<0?(24+h_diff)*60:h_diff*60));
		return ret;
	}
};