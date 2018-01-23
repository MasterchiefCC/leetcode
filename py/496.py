class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        MyMap = {}
        stack = []
        for num in nums:
            while stack and stack[-1] < num:
                MyMap[stack.pop()] = num
            stack.append(num)
        return [MyMap.get(num, -1) for num in findNums]