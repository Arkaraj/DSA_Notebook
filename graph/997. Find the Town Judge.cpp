class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1 && trust.size() == 0)
            return 1;
        vector<int> trusted(n + 1, 0); // creating array from 0 to n+1
        for(auto person : trust){
            trusted[person[0]]--;
            trusted[person[1]]++;
        }
        for(int i = 1;i <= n;i++){
            if(trusted[i] == n - 1) // judge will have n-1 trusts
                return i;
        }
        return -1;
    }
};