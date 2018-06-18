#include"mod.h"
class Solution_BFS {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string>visited(deadends.begin(), deadends.end());
		string start = "0000";
		if (visited.count(start))return -1;
		queue<string>m_queue;
		m_queue.push(start);
		int ret = 0;
		while (!m_queue.empty()) {
			int len = m_queue.size();
			for (int i = 0; i<len; ++i) {
				string temp = m_queue.front();
				m_queue.pop();
				if (temp == target)return ret;
				for (int j = -1; j <= 1; j += 2) {
					for (int k = 0; k<4; ++k) {
						string temp_push = temp;
						if (temp_push[k] == '9'&&j == 1)temp_push[k] = '0';
						else if (temp_push[k] == '0'&&j == -1)temp_push[k] = '9';
						else temp_push[k] += j;
						if (visited.find(temp_push) == visited.end()) {
							m_queue.push(temp_push);
							visited.insert(temp_push);
						}
					}
				}
			}
			++ret;
		}
		return -1;
	}
};