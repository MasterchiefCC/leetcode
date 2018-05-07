#include "mod.h"
class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		int move_temp[] = { 1,-2,2,-1,1,2,2,1,-1,-2,-2,-1,-1,2,-2,1 };
		vector<int>moves(move_temp, move_temp + sizeof(move_temp) / sizeof(int));
		vector<vector<long>>pre_dp(N, vector<long>(N, 0));
		pre_dp[r][c] = 1;
		for (int cur_k = 0; cur_k<K; ++cur_k) {
			vector<vector<long>>cur_dp(N, vector<long>(N, 0));
			for (int i = 0; i<N; ++i) {
				for (int j = 0; j<N; ++j) {
					for (int move = 0; move<moves.size() - 1; move += 2) {
						int x = i + moves[move];
						int y = j + moves[move + 1];
						if (x<0 || x >= N || y<0 || y >= N)continue;
						cur_dp[i][j] += pre_dp[x][y];
					}
				}
			}
			pre_dp = cur_dp;
		}

		double ret = 0;
		for (int i = 0; i<N; ++i) {
			for (int j = 0; j<N; ++j)ret += pre_dp[i][j];
		}
		return ret / pow(8, K);
	}
};
int main() {
	int nums[] = { 2, 1, 4, 3 };
	int nums1[] = { 0,0,0,0,1 };
	vector<int>buffer0(nums, nums + sizeof(nums) / sizeof(nums[0]));
	vector<int>buffer1(nums1, nums1 + sizeof(nums1) / sizeof(nums1[0]));
	Solution test;
	test.knightProbability(8,30,6,4);

	return 0;
}