int t[201][201][2];
int mod = 1003;
int func(string &S, int i, int j, bool isTrue)
{
    if (i > j)
    {
        t[i][j][isTrue] = false;
    }
    if (i == j)
    {
        if (isTrue)
            t[i][j][1] = S[i] == 'T';
        else
            t[i][j][0] = S[i] == 'F';
        return t[i][j][isTrue];
    }
    if (t[i][j][isTrue] != -1)
    {
        return t[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int LT = func(S, i, k - 1, true);
        int LF = func(S, i, k - 1, false);
        int RT = func(S, k + 1, j, true);
        int RF = func(S, k + 1, j, false);
        if (S[k] == '|')
        {
            if (isTrue == true)
                ans += (LT * RF) + (LF * RT) + (LT * RT);
            else
                ans += (LF * RF);
        }
        else if (S[k] == '&')
        {
            if (isTrue == true)
                ans += (LT * RT);
            else
                ans += (LF * RT) + (LT * RF) + (LF * RF);
        }
        else if (S[k] == '^')
        {
            if (isTrue == true)
                ans += (LT * RF) + (LF * RT);
            else
                ans += (LT * RT) + (LF * RF);
        }
    }
    return t[i][j][isTrue] = ans % mod;
}
int countWays(int N, string S)
{
    t[N][N][2];
    memset(t, -1, sizeof(t));
    return func(S, 0, N - 1, true);
}