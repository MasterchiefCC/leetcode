class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        size, colors=len(graph), {};
        def dfs(graph, cur, color, colors):
            if cur in colors:
                return colors[cur]==color;
            colors[cur]=color;
            return all(dfs(graph, next, -color, colors)for next in graph[cur]);
        
        return all(i in colors or dfs(graph, i, 1, colors)for i in range(size));