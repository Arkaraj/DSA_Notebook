#include<iostream>

class Solution {
    public:
	void dfs(int i, vector<int> &vis, stack<int> &stk, vector<int> adj[]) {
	    vis[i]=1;
	    for(auto it: adj[i]) {
	        if(!vis[it]) {
	            dfs(it, vis, stk, adj);
	        } 
	    }
	    stk.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V), res;
	    stack<int> stk;
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, stk, adj);
	        }
	    }
	    while(!stk.empty()) {
	        int t = stk.top();
	        res.push_back(t);
	        stk.pop();
	    }
	    return res;
	}
};