class Solution {
    // isCyclic
    bool dfs(int i, vector<int>& vis, vector<vector<int>>& adj)
    {
        // States: 0 - not visited, 1 - processed, 2 - processing
        if(vis[i]==2)
            return true;
        
        vis[i] = 2;
        for(int it: adj[i])
            if(vis[it]!=1)
                if(dfs(it, vis, adj))
                    return true;
        
        vis[i] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<pr.size();++i)
            adj[pr[i][0]].push_back(pr[i][1]);
        
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(visited[i]==0)
                if(dfs(i, visited, adj))
                    return false;
        
        return true;
    }
};