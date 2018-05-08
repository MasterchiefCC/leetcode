#include "mod.h"
//top->down
//Space O(kn)
class Solution_first {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		vector<double>sum(A.size() + 1, 0.0);
		vector<vector<double>>dp(K, vector<double>(A.size(), 0.0));
		for (int i = 1; i <= A.size(); ++i) {
			sum[i] = A[i - 1] + sum[i - 1];
			dp[0][i - 1] = static_cast<double>(sum[i]) / i;
		}
		sum.erase(sum.begin());

		for (int k = 1; k<K; ++k) {
			for (int i = k; i<A.size(); ++i){
				for (int j = k - 1; j<i; ++j){
					dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sum[i] - sum[j]) / (i - j));
                }
            }
		}
		return dp.back().back();
	}
};
//Space with O(n)
class Solution_second {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		vector<double>sum(A.size() + 1, 0.0);
		vector<double>pre_dp(A.size(), 0.0);
		for (int i = 1; i <= A.size(); ++i) {
			sum[i] = sum[i - 1] + A[i - 1];
			pre_dp[i - 1] = static_cast<double>(sum[i]) / i;
		}
		sum.erase(sum.begin());
        
		for (int k = 1; k<K; ++k) {
			vector<double>cur_dp(A.size(), 0.0);
			for (int i = k; i<A.size(); ++i) {
				for (int j = k - 1; j<i; ++j) {
					cur_dp[i] = max(cur_dp[i], pre_dp[j] + (sum[i] - sum[j]) / (i - j));
				}
			}
			pre_dp = cur_dp;
		}
		return pre_dp.back();
	}
};
