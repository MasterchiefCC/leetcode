class Solution(object):
    def helper(self, grid, x, y):
        ret=0;
        buffer_x=[-1, 0, 1, 0];
        buffer_y=[0, 1, 0, -1];
        for i in range(4):
            temp_x=x+buffer_x[i];
            temp_y=y+buffer_y[i];
            if temp_x<0 or temp_y<0 or temp_x>=len(grid) or temp_y>=len(grid[temp_x]) or grid[temp_x][temp_y]==0:
                ret=ret+1;
        return ret;
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ret=0;
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]:
                    ret+=self.helper(grid, i, j);
        return ret;