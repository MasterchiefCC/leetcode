class Solution {
public:
	int maxProduct(vector<string>& words) {
		int len = words.size(), ret = 0;
		vector<int>buffer(len, 0);
		for (int i = 0; i<len; ++i) {
			for (int j = 0; j<words[i].size(); ++j) {
				buffer[i]|=1<<(words[i][j] - 'a');
			}
		}

		for (int i = 0; i<len; ++i) {
			for (int j = i + 1; j<len; ++j) {
				if (buffer[i] & buffer[j])continue;
				ret = max(ret, (int)(words[i].size()*words[j].size()));
			}
		}
		return ret;
	}
};
