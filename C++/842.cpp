#include"mod.h"
class Solution {
public:
	vector<int> splitIntoFibonacci(string S) {
		vector<int>buffer;
		for (const char& c : S)buffer.push_back(c - '0');
		vector<int>ret;
		dfs(buffer, ret, 0);
		return ret;
	}
private:
	inline int to_int(const vector<int>& buffer, int start, int end) {
		if (buffer[start] == 0 && end - start != 0)return -1;
		int ret = 0;
		for (int i = start; i <= end; ++i) {
			if (ret>INT_MAX / 10)return -1;
			ret *= 10;
			ret += buffer[i];
		}
		return ret;
	}
	bool dfs(const vector<int>& buffer, vector<int>& ret, int level) {
		int len = ret.size();

		if (len >= 3 && ret[len - 2] + ret[len - 3] != ret[len - 1])return false;
		if (level >= buffer.size() && ret.size()<3)return false;
		if (level >= buffer.size() && ret.size() >= 3)return true;

		for (int i = level; i<buffer.size(); ++i) {
			int temp = to_int(buffer, level, i);
			if (temp == -1)continue;
			ret.push_back(temp);
			if (dfs(buffer, ret, i + 1))return true;
			ret.pop_back();
		}
		return false;
	}
};