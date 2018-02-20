class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt=0;
        cur_temp=0;
        for i in range(len(nums)):
            if nums[i]==1:
                cur_temp+=1;
                cnt=max(cur_temp, cnt);
            else:
                cur_temp=0;
        return cnt;
            