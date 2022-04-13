class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        if(n == 1) {
            res[0][0]=1;
            return res;
        }
        // res.resize(n);
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(int i = c1; i <= c2; ++i)
                res[r1][i] = ++val;
				
			// move down(col will be fixed)
            for(int i = r1+1; i <= r2; ++i)
                res[i][c2] = ++val;
				
            // move right to left
            // move  up
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    res[r2][i] = ++val;
					
				// move up (col will be fixed)
				for(int i = r2; i>r1; --i) 
                    res[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return res;
    }
};