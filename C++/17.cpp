#include "mod.h"
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>buffer, ret;
        if(digits.empty())return buffer;
		
        for (const char& digit : digits) {
			buffer.push_back(getLetters(digit - '0'));
		}
		string temp;

		dfs(buffer, 0, temp, ret);
		return ret;
	}
private:
	inline string getLetters(int number) {
		switch (number) {
		case 2:return "abc";
		case 3:return "def";
		case 4:return "ghi";
		case 5:return "jkl";
		case 6:return "mno";
		case 7:return "qprs";
		case 8:return "tuv";
		case 9:return "wxyz";
		default:return "";
		}
	}
	void dfs(const vector<string>& buffer, int level, string &cur, vector<string>& ret) {
		if (level >= buffer.size()) {
			ret.push_back(cur);
			return;
		}
		for (int i = 0; i<buffer[level].size(); ++i) {
			cur.push_back(buffer[level][i]);
			dfs(buffer, level + 1, cur, ret);
			cur.pop_back();
		}
	}
};