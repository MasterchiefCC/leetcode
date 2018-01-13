#include "mod.h"
class Solution {
	static bool Mycom(pair<int, int>p1, pair<int, int>p2) {
		return p1.first < p2.first;
	}
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<pair<int, int>>buffer;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				buffer.push_back(make_pair(nums[i][j], i));
			}
		}
		sort(buffer.begin(), buffer.end(), Mycom);

		int left = 0;
		vector<int>ret(2, -1);
		vector <int>used(len, 0);
		int cnt = 0;
		int diff = INT_MAX;
		for (int right = 0; right < buffer.size(); right++) {
			if (used[buffer[right].second] == 0)cnt++;
			used[buffer[right].second]++;
			while (cnt == len && left <= right) {
				int new_diff = buffer[right].first - buffer[left].first;
				if (diff > new_diff) {
					diff = new_diff;
					ret[0] = buffer[left].first;
					ret[1] = buffer[right].first;
				}
				if(--used[buffer[left].second]==0)cnt--;
				left++;
			}
		}
		return ret;
	}
};