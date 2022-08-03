//using dfs--------->

bool checkBipartite(int i,vector<int> &coloured,vector<vector<int>>& graph)
    {
        for(auto it:graph[i])
        {
            if(coloured[it]==-1)
            {
                coloured[it]=1-coloured[i];
                if(!checkBipartite(it,coloured,graph))
                    return false;
            }
            else if(coloured[it]==coloured[i])
                return false;   
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> coloured(graph.size(),-1);
        for(int i=0;i<n;i++)
        {
            if(coloured[i]==-1)
            {
                coloured[i]=0;
                if(!checkBipartite(i,coloured,graph))
                    return false;
            } 
        }
        return true;
    }

    //using bfs---------->
    bool checkBipartite(int i,vector<int> &coloured,vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(i);
        coloured[i]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it:graph[curr])
            {
                if(coloured[it]==-1)
                {
                    coloured[it]=1-coloured[curr];
                    q.push(it);
                }
                else if(coloured[it]==coloured[curr])
                    return false;
            }
        } 
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> coloured(graph.size(),-1);
        for(int i=0;i<n;i++)
        {
            if(coloured[i]==-1)
            {
                if(!checkBipartite(i,coloured,graph))
                    return false;
            }
        }
        return true;
    }