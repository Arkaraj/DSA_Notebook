class Solution {
public:
    bool colour(int i, vector<vector<int>>& graph, vector<int> &coloured) {
        queue<int> q;
        q.push(i);
        coloured[i]=1;
        while(!q.empty()) {
            int id = q.front();
            q.pop();
            
            for(int it: graph[id]) {
                if(coloured[it]==-1) {
                    coloured[it]=1-coloured[id]; // !coloured[id]
                    q.push(it);
                } else if(coloured[it] == coloured[id]){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> coloured(n, -1);
        // -1 - not coloured, 0 - red, 1 - blue
        for(int i = 0; i < n; i++) {
            if(coloured[i]==-1) {
                if(!colour(i, graph, coloured)) return false;
            }
        }
        return true;
    }
};