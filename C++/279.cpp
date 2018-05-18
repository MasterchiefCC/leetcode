#include "mod.h"
class Solution {
public:
	int numSquares(int n) {
		if (n<4)return n;
		vector<int>dp(n + 1, INT_MAX), perfect;
		dp[0] = 0;
		for (int i = 1; i<dp.size(); ++i) {
			if (is_perfect(i)) {
				dp[i] = 1;
				perfect.push_back(i);
				continue;
			}

			for (int j = 0; j<perfect.size(); ++j) 
				dp[i] = min(dp[i], (i / perfect[j]) + dp[i%perfect[j]]);
		}
		return dp.back();
	}
private:
	bool is_perfect(const int &n) {
		int i = 1;
		while (1) {
			int num = i * i;
			if (num == n)return true;
			if (num>n)return false;
			++i;
		}
		return false;
	}
};