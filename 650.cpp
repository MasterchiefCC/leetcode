class Solution {
public:
    int minSteps(int n) {
        vector<int>buffer(n+1, INT_MAX);
        buffer[1]=0;buffer[2]=2;
        for(int num=3; num<=n; ++num){
            for(int dtor=num-1; dtor>=1; --dtor){
                if(num%dtor==0){
                    buffer[num]=min(buffer[num],buffer[dtor]+num/dtor);
                }
            }
        }
        return buffer[n];
    }
};