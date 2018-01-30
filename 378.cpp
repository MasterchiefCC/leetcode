class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>buffer;
        for(int i=0; i<matrix.size(); ++i)
            buffer.insert(buffer.end(), matrix[i].begin(), matrix[i].end());
        sort(buffer.begin(),buffer.end());
        return buffer[k-1];
    }
};