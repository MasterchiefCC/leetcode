class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        tot_num=r*c;
        cur_num=len(nums)*len(nums[0]);
        if tot_num!= cur_num:
            return nums;
        ret=[[]];
        ret_x=0;
        for x in range(len(nums)):
            for y in range(len(nums[x])):
                ret[ret_x].append(nums[x][y])
                if len(ret[ret_x])==c:
                    ret.append([]);
                    ret_x=ret_x+1;
        x=len(ret);
        if ret[x-1]==[]:
            del ret[x-1];
        return ret;

        