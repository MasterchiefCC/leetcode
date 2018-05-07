class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer>m_map=new HashMap<Integer, Integer>();
        m_map.put(0, 1);
        int ret=0, sum=0;
        for(int i=0; i<nums.length; ++i){
            sum+=nums[i];
            if(m_map.containsKey(sum-k))ret+=m_map.get(sum-k);
            m_map.put(sum, m_map.getOrDefault(sum, 0)+1);
        }
        return ret;
    }
}