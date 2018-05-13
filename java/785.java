class Solution_DFS {
    public boolean isBipartite(int[][] graph) {
        int []colors=new int [graph.length];
        
        for(int i=0; i<graph.length; ++i){
            if(colors[i]==0&&!helper(graph, colors, i, 1))return false;
        }
        return true;
    }
    private boolean helper(final int [][]graph, int []colors, int cur, int color){
        if(colors[cur]!=0)return colors[cur]==color;
        colors[cur]=color;
        for(int i=0; i<graph[cur].length; ++i){
            if(!helper(graph, colors, graph[cur][i], -1*color))return false;
        }
        return true;
    }
}

class Solution_BTF{
    public boolean isBipartite(int[][] graph) {
        int []colors=new int[graph.length];
        
        for(int i=0; i<colors.length; ++i){
            if(colors[i]!=0)continue;
            Queue<Integer>m_queue=new LinkedList<Integer>();
            colors[i]=1;
            m_queue.offer(i);
            while(!m_queue.isEmpty()){
                int cur=m_queue.poll().intValue();
                for(int next:graph[cur]){
                    if(colors[next]==0){
                        colors[next]=-1*colors[cur];
                        m_queue.offer(next);
                    }
                    else if(colors[next]==colors[cur])return false;
                }
            }
        }
        return true;
    }
}