#include "mod.h"
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>ret(n, vector<int>(n, 0));
		int cnt = 1, x = 0, y = 0;
		for (int i = 0; i<n / 2; ++i) {
			int len = n - 1 - i;
			for (int j = i; j<len; ++j)
				ret[i][j] = cnt++;
			for (int j = i; j<len; ++j)
				ret[j][len] = cnt++;
			for (int j = len; j>i; --j)
				ret[len][j] = cnt++;
			for (int j = len; j>i; --j)
				ret[j][i] = cnt++;
		}
		if (n % 2 == 1)ret[n / 2][n / 2] = cnt++;

		return ret;
	}
};