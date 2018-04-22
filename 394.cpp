#include "mod.h"
class Solution {
	int str_end_helper(string &str, const int &str_start) {
		for (int i = str_start + 1, cnt = 1; i<str.size() && cnt != 0; ++i) {
			if (str[i] == '[')++cnt;
			else if (str[i] == ']')--cnt;
			if (cnt == 0)return i;
		}
	}
    
	string helper(string str) {
		string ret;
		int k_start = str.find_first_of("0123456789", 0);

		if (k_start == string::npos) {
			return str;
		}

		if (k_start != 0) {
			ret += str.substr(0, k_start);
		}

		while (k_start != string::npos) {
			int str_start = str.find_first_of('[', k_start);
			int str_end = str_end_helper(str, str_start);

			int k = stoi(str.substr(k_start, str_start - k_start));

			string temp = helper(str.substr(str_start + 1, str_end - 1 - str_start));

			for (int i = 0; i<k; ++i)
				ret += temp;

			k_start = str.find_first_of("0123456789", str_end + 1);

			if (k_start == string::npos) {
				ret += str.substr(str_end + 1);
				break;
			}

			if (k_start != str_end + 1) {
				int tmp = k_start -( str_end + 1);
				ret += str.substr(str_end + 1, k_start - (str_end + 1));
			}
		}
		return ret;
	}
public:
	string decodeString(string s) {
		string ret = helper(s);
		return ret;
	}
};