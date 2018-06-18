#include "mod.h"

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		sort(words.begin(), words.end(), \
             [](const string &s1, const string &s2){
                return s1.size()>s2.size(); 
        });
		unordered_set<string>m_set;
		vector<bool>used(words.size(), false);
		for (int i = 0; i<words.size(); ++i) {
			if (m_set.find(words[i]) == m_set.end()) {
				used[i] = true;
				for (int j = 0; j<words[i].size(); ++j)m_set.insert(words[i].substr(j));
			}
		}
		int ret = 0;
		for (int i = 0; i<used.size(); ++i)ret += used[i] == true ? (words[i].size() + 1) : 0;
		return ret;
	}
};