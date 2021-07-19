//Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    //set the two ending ptrs
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (M[i][j] == 1)
            i++;
        else
            j--;
    }
    //check auth of i
    for (int k = 0; k < n; k++)
    {
        if (k == i)
            continue;
        if (M[k][i] != 1 || M[i][k] == 1)
            return -1;
    }
    return i;
}