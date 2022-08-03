//using dfs-------------->
bool checkForCycle(int node,int parent,vector<int> &visited,vector<int> adj[])
    {
        visited[node]=true;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                if(checkForCycle(it,node,visited,adj))
                {
                  return true;   
                }
            }
            else if(it!=parent)
            return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(checkForCycle(i,-1,visited,adj))
                return true;
            }
        }
        return false;
    }