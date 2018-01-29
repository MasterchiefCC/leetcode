class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len=arr.size(), ret=1;
        if(len==0)return 0;
        for(int n=len-1; n>=0; --n){
            int left=*min_element(arr.begin()+n, arr.end()), right=*max_element(arr.begin(), arr.begin()+n);
            if(left>right)++ret;
        }
        return ret;
    }
};