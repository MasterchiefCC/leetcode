#include"mod.h"
class Solution {
public:
	int maximumSwap(int num) {
		pair<vector<int>, vector<int>>temp = helper(num);
		vector<int> &ori = temp.first;
		vector<int> &b_sort = temp.second;
		int index = -1;
	    
        for (int i = 0; i<ori.size(); ++i) {
			if (ori[i] != b_sort[i]) {
				index = i;
                break;
			}
		}
		if (index == -1)return num;
		int to_swap = index;
		for (int i = index; i<ori.size(); ++i)
			if (ori[i] == b_sort[index])to_swap = i;
		
        swap(ori[index], ori[to_swap]);
        int ret = 0;
		
		for (int i = 0; i<ori.size(); ++i) {
			ret *= 10;
			ret += ori[i];
		}
		return ret;
	}
private:
	pair<vector<int>, vector<int>> helper(int num) {
		vector<int>buffer;
		while (num>0) {
			buffer.push_back(num % 10);
			num /= 10;
		}

		reverse(buffer.begin(), buffer.end());
		pair<vector<int>, vector<int>>ret;
		ret.first = buffer;
		sort(buffer.begin(), buffer.end(), greater<int>());
		ret.second = buffer;
		return ret;
	}
};