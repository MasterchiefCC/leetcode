class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sum=ret=0;
        m_map=collections.Counter();
        m_map[0]=1;
        for num in nums:
            sum+=num;
            ret+=m_map[sum-k];
            m_map[sum]+=1;
        return ret;