class Solution {
    public:
    bool checkCycle(int i, int V, vector<int> &vis, vector<int> adj[]) {
        queue<pair<int, int>> q; // <index, parent>
        q.push({i,-1});
        vis[i] = 1;
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            for(auto it: adj[top.first]) {
                if(!vis[it]) {
                    vis[it]=1;
                    q.push({it, top.first});
                } 
                else if(top.second != it) {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V);
                
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(checkCycle(i, V, vis, adj))
                    return true;
            }
        }
        return false;
    }
};