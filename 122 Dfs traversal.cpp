void dfs(int s, vector < bool > & vis, vector < int > & ans, vector < int > adj[]) {
      ans.push_back(s);
      vis[s] = true;
      for (auto ele: adj[s]) {
        if (!vis[ele]) {
          dfs(ele, vis, ans, adj);
        }
      }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector < bool > vis(V, false);
        vector < int > ans;
        for (int i = 0; i < V; i++)
          if (!vis[i])
            dfs(i, vis, ans, adj);
        return ans;
  }