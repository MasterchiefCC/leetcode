#include "mod.h"
class Solution {
public:
	string reorganizeString(string S) {
		string ret;
		map<char, int>m_map;
		for (const char& c : S)++m_map[c];
		auto cmp = [](const pair<char, int>& lhs, const pair<char, int>& rhs) {return lhs.second < rhs.second; };

		priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>m_pq(cmp);
		for (auto it : m_map) {
			if (it.second>(S.size() + 1) / 2)return "";
			m_pq.push(make_pair(it.first, it.second));
		}
		while (m_pq.size() >= 2) {
			pair<char, int>p1 = m_pq.top(); m_pq.pop();
			pair<char, int>p2 = m_pq.top(); m_pq.pop();
			ret.push_back(p1.first);
            ret.push_back(p2.first);
			if (--p1.second>0)m_pq.push(p1);
			if (--p2.second>0)m_pq.push(p2);
		}

		while (!m_pq.empty()) { ret.push_back(m_pq.top().first); m_pq.pop(); }
		return ret;
	}
};
