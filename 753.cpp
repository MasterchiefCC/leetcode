#include "mod.h"

class Solution {
public:
	string crackSafe(int n, int k) {
		string ret(n, '0');
		string cur(n - 1, '0');
		unordered_set<string> used;
		used.insert(ret);
		while (1) {
			bool ok = 1;
			for (int i = k - 1; i >= 0; i--) {
				string temp = cur + (char)('0' + i);
				if (used.find(temp) == used.end()) {
					ret += '0' + i;
					cur = temp.substr(1);
					used.insert(temp);
					ok = 0;
					break;
				}
			}
			if (ok)break;
		}
		return ret;
	}
};