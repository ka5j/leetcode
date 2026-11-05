class Solution {
public:
    unordered_set<char> row0;
    unordered_set<char> row1;
    unordered_set<char> row2;
    unordered_set<char> row3;
    unordered_set<char> row4;
    unordered_set<char> row5;
    unordered_set<char> row6;
    unordered_set<char> row7;
    unordered_set<char> row8;

    unordered_set<char> column0;
    unordered_set<char> column1;
    unordered_set<char> column2;
    unordered_set<char> column3;
    unordered_set<char> column4;
    unordered_set<char> column5;
    unordered_set<char> column6;
    unordered_set<char> column7;
    unordered_set<char> column8;

    unordered_set<char> block0;
    unordered_set<char> block1;
    unordered_set<char> block2;
    unordered_set<char> block3;
    unordered_set<char> block4;
    unordered_set<char> block5;
    unordered_set<char> block6;
    unordered_set<char> block7;
    unordered_set<char> block8;

    bool isValidSudoku(vector<vector<char>>& board) {
        bool isSudokuValid = true;
        for(int row = 0; row < board.size(); row++)
        {
            for(int column = 0; column < board[0].size(); column++)
            {
                if(board[row][column] != '.')
                {
                    isSudokuValid = fillSet(row, column, board[row][column]);
                    if(!isSudokuValid)
                    {
                        return false;
                    }
                }
            }
        }
        return isSudokuValid;
    }

    bool fillSet(int row, int column, char num)
    {
        if((row == 0) && (column == 0))
        {
            if(row0.contains(num) || column0.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column0.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 1))
        {
            if(row0.contains(num) || column1.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column1.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 2))
        {
            if(row0.contains(num) || column2.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column2.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 3))
        {
            if(row0.contains(num) || column3.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column3.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 4))
        {
            if(row0.contains(num) || column4.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column4.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 5))
        {
            if(row0.contains(num) || column5.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column5.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 6))
        {
            if(row0.contains(num) || column6.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column6.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 7))
        {
            if(row0.contains(num) || column7.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column7.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 0) && (column == 8))
        {
            if(row0.contains(num) || column8.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row0.insert(num);
                column8.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 0))
        {
            if(row1.contains(num) || column0.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column0.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 1))
        {
            if(row1.contains(num) || column1.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column1.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 2))
        {
            if(row1.contains(num) || column2.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column2.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 3))
        {
            if(row1.contains(num) || column3.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column3.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 4))
        {
            if(row1.contains(num) || column4.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column4.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 5))
        {
            if(row1.contains(num) || column5.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column5.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 6))
        {
            if(row1.contains(num) || column6.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column6.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 7))
        {
            if(row1.contains(num) || column7.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column7.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 1) && (column == 8))
        {
            if(row1.contains(num) || column8.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row1.insert(num);
                column8.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 0))
        {
            if(row2.contains(num) || column0.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column0.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 1))
        {
            if(row2.contains(num) || column1.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column1.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 2))
        {
            if(row2.contains(num) || column2.contains(num) || block0.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column2.insert(num);
                block0.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 3))
        {
            if(row2.contains(num) || column3.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column3.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 4))
        {
            if(row2.contains(num) || column4.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column4.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 5))
        {
            if(row2.contains(num) || column5.contains(num) || block1.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column5.insert(num);
                block1.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 6))
        {
            if(row2.contains(num) || column6.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column6.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 7))
        {
            if(row2.contains(num) || column7.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column7.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 2) && (column == 8))
        {
            if(row2.contains(num) || column8.contains(num) || block2.contains(num))
            {
                return false;
            }
            else
            {
                row2.insert(num);
                column8.insert(num);
                block2.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 0))
        {
            if(row3.contains(num) || column0.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column0.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 1))
        {
            if(row3.contains(num) || column1.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column1.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 2))
        {
            if(row3.contains(num) || column2.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column2.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 3))
        {
            if(row3.contains(num) || column3.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column3.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 4))
        {
            if(row3.contains(num) || column4.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column4.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 5))
        {
            if(row3.contains(num) || column5.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column5.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 6))
        {
            if(row3.contains(num) || column6.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column6.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 7))
        {
            if(row3.contains(num) || column7.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column7.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 3) && (column == 8))
        {
            if(row3.contains(num) || column8.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row3.insert(num);
                column8.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 0))
        {
            if(row4.contains(num) || column0.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column0.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 1))
        {
            if(row4.contains(num) || column1.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column1.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 2))
        {
            if(row4.contains(num) || column2.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column2.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 3))
        {
            if(row4.contains(num) || column3.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column3.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 4))
        {
            if(row4.contains(num) || column4.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column4.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 5))
        {
            if(row4.contains(num) || column5.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column5.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 6))
        {
            if(row4.contains(num) || column6.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column6.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 7))
        {
            if(row4.contains(num) || column7.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column7.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 4) && (column == 8))
        {
            if(row4.contains(num) || column8.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row4.insert(num);
                column8.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 0))
        {
            if(row5.contains(num) || column0.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column0.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 1))
        {
            if(row5.contains(num) || column1.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column1.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 2))
        {
            if(row5.contains(num) || column2.contains(num) || block3.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column2.insert(num);
                block3.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 3))
        {
            if(row5.contains(num) || column3.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column3.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 4))
        {
            if(row5.contains(num) || column4.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column4.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 5))
        {
            if(row5.contains(num) || column5.contains(num) || block4.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column5.insert(num);
                block4.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 6))
        {
            if(row5.contains(num) || column6.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column6.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 7))
        {
            if(row5.contains(num) || column7.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column7.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 5) && (column == 8))
        {
            if(row5.contains(num) || column8.contains(num) || block5.contains(num))
            {
                return false;
            }
            else
            {
                row5.insert(num);
                column8.insert(num);
                block5.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 0))
        {
            if(row6.contains(num) || column0.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column0.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 1))
        {
            if(row6.contains(num) || column1.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column1.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 2))
        {
            if(row6.contains(num) || column2.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column2.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 3))
        {
            if(row6.contains(num) || column3.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column3.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 4))
        {
            if(row6.contains(num) || column4.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column4.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 5))
        {
            if(row6.contains(num) || column5.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column5.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 6))
        {
            if(row6.contains(num) || column6.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column6.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 7))
        {
            if(row6.contains(num) || column7.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column7.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 6) && (column == 8))
        {
            if(row6.contains(num) || column8.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row6.insert(num);
                column8.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 0))
        {
            if(row7.contains(num) || column0.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column0.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 1))
        {
            if(row7.contains(num) || column1.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column1.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 2))
        {
            if(row7.contains(num) || column2.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column2.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 3))
        {
            if(row7.contains(num) || column3.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column3.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 4))
        {
            if(row7.contains(num) || column4.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column4.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 5))
        {
            if(row7.contains(num) || column5.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column5.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 6))
        {
            if(row7.contains(num) || column6.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column6.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 7))
        {
            if(row7.contains(num) || column7.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column7.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 7) && (column == 8))
        {
            if(row7.contains(num) || column8.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row7.insert(num);
                column8.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 0))
        {
            if(row8.contains(num) || column0.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column0.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 1))
        {
            if(row8.contains(num) || column1.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column1.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 2))
        {
            if(row8.contains(num) || column2.contains(num) || block6.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column2.insert(num);
                block6.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 3))
        {
            if(row8.contains(num) || column3.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column3.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 4))
        {
            if(row8.contains(num) || column4.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column4.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 5))
        {
            if(row8.contains(num) || column5.contains(num) || block7.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column5.insert(num);
                block7.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 6))
        {
            if(row8.contains(num) || column6.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column6.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 7))
        {
            if(row8.contains(num) || column7.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column7.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else if((row == 8) && (column == 8))
        {
            if(row8.contains(num) || column8.contains(num) || block8.contains(num))
            {
                return false;
            }
            else
            {
                row8.insert(num);
                column8.insert(num);
                block8.insert(num);
                return true;
            }
        }
        else
        {
            return false; // row/column out of range
        }
    }
};
