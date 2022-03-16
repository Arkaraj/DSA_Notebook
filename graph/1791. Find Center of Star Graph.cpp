class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 3 <= n, given, so edges[1] will exist
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0]: edges[0][1];
    }
};