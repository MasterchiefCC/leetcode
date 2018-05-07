#include"mod.h"
class Solution {
	void helper(vector<int> &buffer, int cur_n, const int &n) {
		if (cur_n>n)return;
		int cnt = pow(2, cur_n - 1);
		int len = buffer.size();
		for (int i = buffer.size()-1; i>=0; --i)
			buffer.push_back(buffer[i] + cnt);
		helper(buffer, cur_n + 1, n);
	}
public:
	vector<int> grayCode(int n) {
		vector<int>buffer(1, 0);
		if (n == 0)return buffer;
		buffer.resize(2, 1);
		buffer[0] = 0;
		helper(buffer, 2, n);
		return buffer;
	}
};