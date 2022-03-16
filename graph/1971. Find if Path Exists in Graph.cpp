class Solution {
public:
    // TLE by my dfs sol 20/26 test cases passed
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // if(n == 1) 
        //     return edges.size()==0;
//         vector<int> seen(n, 0);
//         // dfs
//         stack<int> stk;
//         stk.push(source);
//         seen[source] = 1;
//         while(!stk.empty()) {
//             int top = stk.top();
//             stk.pop();
//             if(top == destination)
//                 return true;
//             for(auto ed: edges) {
//                 if (ed[0] == top && seen[ed[1]]==0) {
//                     stk.push(ed[1]);
//                     seen[ed[1]] = 1;
//                 } else if(ed[1] == top && seen[ed[0]]==0) {
//                     stk.push(ed[0]);
//                     seen[ed[0]] = 1;
//                 }
//             }
            
//         }
//         return false;
        
        vector<vector<int>> graph(n);
        // Build the graph
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        // dfs
        stack<int> stk;
        vector<int> visited(n, 0);
        stk.push(source);
        visited[source] = 1;
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            if(top == destination)
                return true;

            for(int i=0; i<graph[top].size(); i++){
                if(visited[graph[top][i]] == 0){
                    stk.push(graph[top][i]);
                    visited[graph[top][i]] = 1;
                }
            }
        }
        return false;
    }
};