class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island=0, m = grid.size(), n = grid[0].size();
        // vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dir = {0,1,0,-1,0}; // {(0,1), (1,0), (0,-1), (-1,0)}
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                        grid[i][j] = '0';
                        island++;
                        queue<pair<int,int>> bfs;
                        bfs.push({i, j});
                        while(!bfs.empty()) {
                            pair<int,int> p = bfs.front();
                            bfs.pop();
                            // dir
                            for(int k = 0; k < 4; k++) {
                                int r = p.first+dir[k], c = p.second+dir[k+1]; 
                                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                    grid[r][c] = '0';
                                    bfs.push({r,c});
                                }
                            }
                            
                        }
                    }
            }
        }
        
        return island;
    }
};