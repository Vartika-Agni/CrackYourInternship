bool visited[n];

void dfs(int u){
    if(visited[i]==0)
    {
        cout<<u<<" ";
        visited[u]=1;
        for(int v=1; v<=n; v++)
        {
            if(A[u][v]==1 && visited[v]==0)
            dfs(v);
        }
    }
}