#include "mod.h"
class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {

		vector<pair<int, int>>ret;
		if (matrix.empty())return ret;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>>m_pacific(m, vector<bool>(n, false));
		vector<vector<bool>>m_atlantic(m, vector<bool>(n, false));

		for (int i = 0; i < m; ++i) {
			DFS(matrix, m_pacific, INT_MIN, i, 0);
			DFS(matrix, m_atlantic, INT_MIN, i, n - 1);
		}
		for (int i = 0; i < n; ++i) {
			DFS(matrix, m_pacific, INT_MIN, 0, i);
			DFS(matrix, m_atlantic, INT_MIN, m - 1, i);
		}

		for (int i = 0; i<m; ++i)
			for (int j = 0; j<n; ++j)
				if (m_pacific[i][j] && m_atlantic[i][j])ret.push_back(make_pair(i, j));
		return ret;
	}
private:
	void DFS(const vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int i, int j) {
		int m = matrix.size(), n = matrix[0].size();
		if (i<0 || i >= m|| j<0 || j >= n || visited[i][j]==true || matrix[i][j] < pre)return;
		visited[i][j] = true;

		DFS(matrix, visited, matrix[i][j], i + 1, j);
		DFS(matrix, visited, matrix[i][j], i - 1, j);
		DFS(matrix, visited, matrix[i][j], i, j + 1);
		DFS(matrix, visited, matrix[i][j], i, j - 1);
	}
};