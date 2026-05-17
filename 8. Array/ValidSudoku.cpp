#include <bits/stdc++.h>
using namespace std;

/*
(8/Neetcode150)
    Problem Statement
    --------------------
    You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
    - Each row must contain the digits 1-9 without duplicates.
    - Each column must contain the digits 1-9 without duplicates.
    - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
    - Return true if the Sudoku board is valid, otherwise return false
    (Note: A board does not need to be full or be solvable to be valid.)

    Example 1:
    Input: board =
    [["1","2",".",".","3",".",".",".","."],
    ["4",".",".","5",".",".",".",".","."],
    [".","9","8",".",".",".",".",".","3"],
    ["5",".",".",".","6",".",".",".","4"],
    [".",".",".","8",".","3",".",".","5"],
    ["7",".",".",".","2",".",".",".","6"],
    [".",".",".",".",".",".","2",".","."],
    [".",".",".","4","1","9",".",".","8"],
    [".",".",".",".","8",".",".","7","9"]]
    Output: true

    Example 2:
    Input: board =
    [["1","2",".",".","3",".",".",".","."],
    ["4",".",".","5",".",".",".",".","."],
    [".","9","1",".",".",".",".",".","3"],
    ["5",".",".",".","6",".",".",".","4"],
    [".",".",".","8",".","3",".",".","5"],
    ["7",".",".",".","2",".",".",".","6"],
    [".",".",".",".",".",".","2",".","."],
    [".",".",".","4","1","9",".",".","8"],
    [".",".",".",".","8",".",".","7","9"]]
    Output: false
    Explanation: There are two 1's in the top-left 3x3 sub-box.

    Constraints:
    - board.length == 9
    - board[i].length == 9
    - board[i][j] is a digit 1-9 or '.'.

    Intuition:
    --------------------
    Aproach1: We can keep 3 maps, 1 for rows, 1 for columns and 1 for 3*3 squares mapped to the set of the digit
    lied in that row/column or the squares, and check the three conditions one by one.
    Time complexity: O(n*n), Space complexity: O(n)

    Aproach2: We keep a map of sets, which for each cells stores the digits seen so far, and continue this throughout the matrix.
    Time complexity: O(n*n), Space complexity: O(n*n)
*/

bool validSudoku(vector<vector<string>>& board){
    int n = board.size(); //rows or columns as it is a square;

    for(int row=0; row<n; row++){
        unordered_set<int> seenColumns;
        for(int j=0; j<n; j++){
            if(board[row][j] != "."){
                int num = stoi(board[row][j]);

                if(seenColumns.find(num) != seenColumns.end()){
                    return false;
                }

                seenColumns.insert(num);
            }
        }
    }

    for(int col=0; col<n; col++){
        unordered_set<int> seenRows;
        for(int i=0; i<n; i++){
            if(board[i][col] != "."){
                int num = stoi(board[i][col]);

                if(seenRows.find(num) != seenRows.end()){
                    return false;
                }

                seenRows.insert(num);
            }
        }
    }

    for(int square=0; square<n; square++){
        unordered_set<int> seenSquares;

        for(int i=0; i<(n/3); i++){
            for(int j=0; j<(n/3); j++){
                int row = (square/3)*3 + i;
                int col = (square%3)*3 + j;
                if(board[row][col] != "."){
                    int num = stoi(board[row][col]);

                    if(seenSquares.find(num) != seenSquares.end()){
                        return false;
                    }

                    seenSquares.insert(num);
                }
            }
        }
    }

    return true;
}

bool validSudoku2(vector<vector<string>>& board){
    int n = board.size();

    unordered_map<int, unordered_set<int>> seenInRows, seenInColumns;
    map<pair<int, int>, unordered_set<int>> seenInSquares;

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(board[row][col] != "."){
                int num = stoi(board[row][col]);

                pair<int, int> squareKey = {row/3, col/3};

                if(seenInRows[row].count(num) || seenInColumns[col].count(num) || seenInSquares[squareKey].count(num)){
                    return false;
                }

                seenInRows[row].insert(num);
                seenInColumns[col].insert(num);
                seenInSquares[squareKey].insert(num);
            }
        }
    }

    return true;
}

int main(){

    vector<vector<string>> board = {{"1","2",".",".","3",".",".",".","."},
                                    {"4",".",".","5",".",".",".",".","."},
                                    {".","9","8",".",".",".",".",".","3"},
                                    {"5",".",".",".","6",".",".",".","4"},
                                    {".",".",".","8",".","3",".",".","5"},
                                    {"7",".",".",".","2",".",".",".","6"},
                                    {".",".",".",".",".",".","2",".","."},
                                    {".",".",".","4","1","9",".",".","8"},
                                    {".",".",".",".","8",".",".","7","9"}};

    cout<<validSudoku2(board)<<endl;

    return 0;
}