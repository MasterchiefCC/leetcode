#include "mod.h"

class Solution {
	void helper(vector<int>&ret, int cur_val, const int &target) {
		if (cur_val>target)return;
		for (int i = 0; i<10; ++i) {
			if (cur_val + i <= target) {
				ret.push_back(cur_val + i);
				if( (cur_val + i) * 10<=target)helper(ret,  (cur_val + i) * 10, target);
			}
            else break;
		}
	}
public:
	vector<int> lexicalOrder(int n) {
		vector<int>ret;
		if (n == 0)return ret;
		helper(ret, 1, n);
		ret.resize(n);
		return ret;
	}
};

// class Solutio2n {
// public:
// 	vector<int> lexicalOrder(int n) {
// 		vector<string>m_arr(n, "");
// 		for (int i = 1; i <= n; ++i)
// 			m_arr[i - 1] = to_string(i);
// 		sort(m_arr.begin(), m_arr.end());
// 		vector<int>ret(n, 0);
// 		for (int i = 0; i<n; ++i)
// 			ret[i] = stoi(m_arr[i]);
// 		return ret;
// 	}
// };