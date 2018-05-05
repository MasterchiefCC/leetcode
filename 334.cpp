class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m_1=INT_MAX, m_2=INT_MAX;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]<=m_1)m_1=nums[i];
            else if(nums[i]<=m_2)m_2=nums[i];
            //nums[i]>m1&&nums[i]>m2 return true
            else return true;
            //[5,1,5,5,2,5,4]
        }
        return false;
    }
};