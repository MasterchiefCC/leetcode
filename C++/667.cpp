#include "mod.h"

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int>ret;
		int start = 1;
		int end = k;
		while(start<=end) {
			ret.push_back(k>1 ? (k-- % 2 ? start++ : end--) : start++);
		}
		return ret;
	}
};