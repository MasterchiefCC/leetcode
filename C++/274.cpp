#include "mod.h"
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int h_idx = 0;
		sort(citations.begin(), citations.end());
		int left = 0, right = citations.size() - 1, len = citations.size();
		while (left<=right) {
			int mid = left + (right - left) / 2, size = len - mid;
				if (citations[mid] == size)return size;
			if (citations[mid]>size)right = mid - 1;
			else left = mid + 1;
		}
		return len - left;
	}
};