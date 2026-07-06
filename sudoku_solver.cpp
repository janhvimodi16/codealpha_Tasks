#include<iostream>
using namespace std;
// ---------- Function to print Sudoko board -----------
void printboard(int board [9][9])
{
    for(int i=0; i<9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Check wheather number can be placed or not 

bool isSafe(int board[9][9],int row, int col, int num)
{
    // Row Check
    for( int x=0; x<9; x++ )
    {
        if (board[row][x] == num)
        {
            return false;
        }
        
    }

    // Column Check 
    for(int x=0; x<9; x++)
    {
        if(board[x][col] == num )
        {
            return false;
        }
    }

    // 3 x 3 Check
    int startrow = row - row % 3;
    int startcol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startrow + i][startcol + j] == num)
            {
                return false;
            }
            
        }
        
    }
    
    return true;
}

// Solve Sudoku Using Backtrsking 
bool Solvesudoku(int board[9] [9])
{
    int row , col;
    bool emptyFound = false;

    // Find Empty Cell
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col <9; col++)
        {
            if (board[row][col] == 0)
            {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound)
        {
            break;
        }
    }

    // No Empty Cell Means Solved 
    if(!emptyFound)
    {
        return true;
    }

    // Try Numbers 1 to 9 
    for(int num = 1; num <=9; num++)
    {
        if(isSafe(board, row, col, num ))
        {
            board[row][col] = num; 

            if (Solvesudoku(board))
            {
                return true;
            }
            
            // Backtrack 
            board[row][col] = 0;

        }
    }
        return false;
}

    int main()
{
    int board[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(Solvesudoku(board))
    {
        cout << "Solved Sudoku:\n";
        printboard(board);
    }
    else
    {
        cout << "No Solution Exists!";
    }

    return 0;
}

