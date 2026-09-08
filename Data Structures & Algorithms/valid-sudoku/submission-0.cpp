class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                char digit = board[i][j];

                int box = (i / 3) * 3 + (j / 3);

                
                if (rows[i].count(digit) ||
                    cols[j].count(digit) ||
                    boxes[box].count(digit)) {
                    return false;
                }

                
                rows[i].insert(digit);
                cols[j].insert(digit);
                boxes[box].insert(digit);
            }
        }

        return true;
    }
};
