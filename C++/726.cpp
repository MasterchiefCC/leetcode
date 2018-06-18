#include "mod.h"
class Solution {
	static bool myComp(pair<string, int>&p1, pair<string, int>&p2) {
		return p1.second > p2.second;
	}
	vector<pair<string, int>> helper(string &formula, int index, int &retpos) {
		vector<pair<string, int>>ret;
		int size = 0;
		int len = formula.size();
		for (int i = index; i < len; i++) {
			if (formula[i] == '(') {
				int pos = 0;
				vector<pair<string, int>>temp = helper(formula, i + 1, pos);

				int j = pos + 1;
				while (j < len&&formula[j] >= '0'&&formula[j] <= '9')j++;
				int cnt = stoi(formula.substr(pos+1, j - pos+1));
				cnt = cnt == 0 ? 1 : cnt;

				for (int z = 0; z < temp.size(); z++, size++) {
					temp[z].second *= cnt;
					ret.push_back(temp[z]);
				}
				i = j - 1;
			}
			else if (formula[i] == ')') { retpos = i; return ret; }
			else if (formula[i] >= 'A'&&formula[i] <= 'Z') {
				int j = i + 1;
				while (j < len&&formula[j] >= 'a'&&formula[j] <= 'z')j++;
				ret.push_back(make_pair(formula.substr(i, j - i), 1));
				size++;
				i = j - 1;
			}
			else if (formula[i] >= '0'&&formula[i] <= '9') {
				int j = i + 1;
				while (j < len&&formula[j] >= '0'&&formula[j] <= '9')j++;
				int cnt = stoi(formula.substr(i, j - i));
				ret[size-1].second *= cnt;
				i = j - 1;
			}
		}
		return ret;
	}
public:
	string countOfAtoms(string formula) {
		int pos = 0;
		vector<pair<string, int>>buffer = helper(formula, 0, pos);
		map<string, int>mymap;
		for (int i = 0; i < buffer.size(); i++)
			mymap[buffer[i].first] += buffer[i].second;
		buffer.clear();
		string ret;
		for (auto mit = mymap.begin(); mit != mymap.end(); mit++)
			ret += mit->first + (mit->second>1?to_string(mit->second):"");
		return ret;
	}
};