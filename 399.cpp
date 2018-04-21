#include "mod.h"
class Solution {
	pair<string, double>& search(const string &target, \
		unordered_map<string, pair<string, double>>& m_map) {
		if (m_map[target].first != target) {
			const pair<string, double>& ret = search(m_map[target].first, m_map);
			m_map[target].first = ret.first;
			m_map[target].second *= ret.second;
		}
		return m_map[target];
	}
public:
	vector<double> calcEquation(const vector<pair<string, string>>& equations, vector<double>& values, const vector<pair<string, string>>& queries) {

		unordered_map<string, pair<string, double>>m_map;

		for (int i = 0; i<equations.size(); ++i) {
			const string &left = equations[i].first;
			const string &right = equations[i].second;
			double &value = values[i];
			if (!m_map.count(left) && !m_map.count(right)) {
				m_map[left] = make_pair(right, value);
				m_map[right] = make_pair(right, 1.0);
			}
			else if (!m_map.count(left)) {
				m_map[left] = make_pair(right, value);
			}
			else if (!m_map.count(right)) {
				m_map[right] = make_pair(left, 1.0 / value);
			}
			else if (m_map.count(right) && m_map.count(left)) {
				pair<string, double>&l_ret = search(left, m_map);
				pair<string, double>&r_ret = search(right, m_map);
				if (l_ret != r_ret) {
					l_ret.first = r_ret.first;
					l_ret.second *= r_ret.second*value;
				}
			}
		}
		vector<double>ret(queries.size(), -1.0);
		for (int i = 0; i<queries.size(); ++i) {
			const string &left = queries[i].first;
			const string &right = queries[i].second;

			if (!m_map.count(left) || !m_map.count(right)) {
				continue;
			}
			pair<string, double>&l_ret = search(left, m_map),
				r_ret = search(right, m_map);

			if (l_ret.first != r_ret.first)continue;
			else ret[i] = (l_ret.second / r_ret.second);
		}

		return ret;
	}
};
int main() {
	pair<string, string>p0;
	p0.first = "a";
	p0.second = "b";
	pair<string, string>p1;
	p1.first = "b";
	p1.second = "c";
	vector<pair<string, string>>equations;
	equations.push_back(p0);
	equations.push_back(p1);

	vector<double>values;
	values.push_back(2.0);
	values.push_back(3.0);

	pair<string, string>p2;
	p2.first = "a";
	p2.second = "c";

	vector<pair<string, string>>queries;
	queries.push_back(p2);

	Solution test;
	auto ret=test.calcEquation(equations, values, queries);


	return 0;
}