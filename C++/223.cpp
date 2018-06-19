#include "mod.h"
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int total = (C - A)*(D - B) + (G - E)*(H - F);
		if (E >= C || A >= G || B >= H || F >= D)return total;
		vector<int>x, y;
		x.push_back(A);
		x.push_back(C);
		x.push_back(E);
		x.push_back(G);

		y.push_back(B);
		y.push_back(D);
		y.push_back(F);
		y.push_back(H);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		return total - (x[2] - x[1])*(y[2] - y[1]);
	}
};