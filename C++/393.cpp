#include "mod.h"
class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int idx = 0;
		while (idx<data.size()) {
			short cur = data[idx];
			short temp = cur & 0x80;
			if ((cur & 0x80) == 0) {
				++idx;
				continue;
			}
			char off = 7, cnt = 0;
			while ((cur >> off )&1== 1) {
				if (cnt == 4)return false;
				++cnt;
				--off;
			}
			--cnt;
			if (cnt == 0)return false;
			while (cnt--) {
				if (++idx >= data.size())return false;
				short temp = data[idx] & 0x0080;
				if (temp != 0x80)return false;
			}
			++idx;
		}
		return true;
	}
};