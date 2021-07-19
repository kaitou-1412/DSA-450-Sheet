//Function to find a solved Sudoku.
// Checks whether it will be
// legal to assign num to the
// given row, col
bool isSafe(int grid[N][N], int row,
            int col, int num)
{

    // Check if we find the same num
    // in the similar row , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    // Check if we find the same num in
    // the similar column , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    // Check if we find the same num in
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                                   startCol] == num)
                return false;

    return true;
}
bool SolveSudoku2(int grid[N][N], int row, int col)
{
    // Check if we have reached the 8th
    // row and 9th column (0
    // indexed matrix) , we are
    // returning true to avoid
    // further backtracking
    if (row == N - 1 && col == N)
        return true;

    // Check if column value  becomes 9 ,
    // we move to next row and
    //  column start from 0
    if (col == N)
    {
        row++;
        col = 0;
    }

    // Check if the current position of
    // the grid already contains
    // value >0, we iterate for next column
    if (grid[row][col] > 0)
        return SolveSudoku2(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        // Check if it is safe to place
        // the num (1-9)  in the
        // given row ,col  ->we
        // move to next column
        if (isSafe(grid, row, col, num))
        {

            /* Assigning the num in 
                  the current (row,col)
                  position of the grid
                  and assuming our assined 
                  num in the position
                  is correct     */
            grid[row][col] = num;

            //  Checking for next possibility with next
            //  column
            if (SolveSudoku2(grid, row, col + 1))
                return true;
        }

        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for
        // next assumption with
        // diff num value
        grid[row][col] = 0;
    }
    return false;
}
bool SolveSudoku(int grid[N][N])
{
    // Your code here
    return SolveSudoku2(grid, 0, 0);
}

//Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    // Your code here
    //cout << "[";
    for (int i = 0; i < N; i++)
    {
        //cout << "[";
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j];
            if (j + i != N + N - 2)
                cout << " ";
        }
        //cout << "]";
        //if(i+1!=N) cout << ",\n";
    }
    //cout << "]\n";
}