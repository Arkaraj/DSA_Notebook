// leetcode: 37. Sudoku Solver

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(int row, int col, char ch, vector<vector<char>>& board) {
       // row check
        for(int i = 0; i < 9; i++) 
            if(board[i][col] == ch) 
                return false;
        // col check
        for(int i = 0; i < 9; i++) 
            if(board[row][i] == ch) 
                return false;
        // box check
        int x = (row/3) * 3, y = (col/3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x + i][y + j] == ch) return false;
            }
        }
        return true;
    }
    bool recursiveHelper(int row, int col, vector<vector<char>>& board) {
        if(row == 9)
            return true;
        if(col == 9)
            return recursiveHelper(row + 1, 0, board);
        
        if(board[row][col] != '.') 
		    return recursiveHelper(row, col + 1, board);
        
        for(int ch = '1'; ch <= '9'; ch++) {
            if(isPossible(row,col, ch, board)) {
                    board[row][col] = ch;
                    // without return here, the board reverts to initial state
                    if(recursiveHelper(row, col + 1, board))
				        return true;
                    board[row][col] = '.';
                }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        recursiveHelper(0,0, board);
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    s.solveSudoku(board);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << ",";
        }
        cout << "\n";
    }
    return 0;
}