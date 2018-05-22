#include "mod.h"
class Solution {
public:
	string pushDominoes(string dominoes) {
		bool with_right = false;
		int right_cnt = 0, idx = -1;
		for (int i = 0; i<dominoes.size(); ++i) {
			if (dominoes[i] == 'R') {
				with_right = true;
				right_cnt = 0;
				idx = i;
			}
			else if (dominoes[i] == 'L') {
				std::fill(dominoes.begin() + idx + (right_cnt / 2)+1, dominoes.begin() + i, 'L');
				if(right_cnt % 2 == 1)dominoes[idx + right_cnt / 2 + 1] = '.';
				idx = i, right_cnt = 0, with_right = false;
			}
			else if (with_right == true) {
				++right_cnt;
				dominoes[i] = 'R';
			}
		}
		return dominoes;
	}
};