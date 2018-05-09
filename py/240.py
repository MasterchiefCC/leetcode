class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix)==0 or len(matrix[0])==0:
            return False;
        row=len(matrix)-1;
        col=0;
        while row>=0 and col<len(matrix[0]):
            if matrix[row][col]==target:
                return True;
            elif matrix[row][col]<target:
                col+=1;
            elif matrix[row][col]>target:
                row-=1;
        return False;