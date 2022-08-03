vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int>visited(V,0);
        queue<int> q;
        vector<int> ans;
        visited[0]=1;
        q.push(0);
        
        while(!q.empty())
        {
            int curr= q.front();
            ans.push_back(curr);
            q.pop();
            
            for(auto it:adj[curr])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }