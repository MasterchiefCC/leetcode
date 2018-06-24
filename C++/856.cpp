#include "mod.h"
class Solution {
public:
	int scoreOfParentheses(string S) {
		stack<int>m_stack;
		for (int i = 0; i<S.size(); ++i) {
			if (S[i] == '(')m_stack.push(INT_MIN);
			else {
				vector<int>buffer;
				while (!m_stack.empty()) {
					int cur = m_stack.top();
					m_stack.pop();
					if (cur == INT_MIN)break;
					else buffer.push_back(cur);
				}
				if (buffer.empty())m_stack.push(1);
				else if (buffer.size() == 1)m_stack.push(buffer[0] * 2);
				else {
					int ret = 0;
					for (int i = 0; i<buffer.size(); ++i)ret += buffer[i];
					m_stack.push(2*ret);
				}
			}
		}

		int ret = 0;
		while (!m_stack.empty()) {
			ret += m_stack.top();
			m_stack.pop();
		}
		return ret;
	}
};

int main() {
	Solution test;
	cout << test.scoreOfParentheses("(()())") << endl;
	return 0;
}