#include"mod.h"
class Solution {
public:
	int lengthLongestPath(string input) {
		int idx = 0, level = 0;
		string cur_dir, ret_dir;
		while (idx<input.size()) {
			int cur_level = 0;
			if (input[idx] == '\n') {
				++idx;
				while (input[idx] == '\t') {
					++cur_level;
					++idx;
				}
			}
			string temp = "/";
			bool is_file = false;
			while (idx<input.size() && input[idx] != '\n') {
				if (input[idx] == '.')is_file = true;
				temp += input[idx];
				++idx;
			}
			for (int i = level - cur_level; i >= 0; --i)
				cur_dir = cur_dir.substr(0, cur_dir.find_last_of('/'));
			cur_dir += temp;
			level = cur_level;
			if (is_file&&cur_dir.size()>ret_dir.size()) {
				ret_dir = cur_dir;
			}
		}
        if(ret_dir.empty())return 0;
        return ret_dir.size()-1;
	}
};