class Solution(object):
    def maxAreaOfIsland(self, grid):
        step=((-1,0), (1,0), (0,-1), (0,1));
        x_len=len(grid);
        y_len=len(grid[0]);
        def helper(grid, x, y):
            if x<0 or x>=x_len or y<0 or y>=y_len or grid[x][y]==0:
                return 0;
            ret=1;
            grid[x][y]=0;
            for i,j in step:
                ret+=helper(grid, x+i, y+j);
            return ret;
        ret=0;
        for x in range(x_len):
            for y in range(y_len):
                ret=max(ret, helper(grid, x, y));
        return ret;