int wordBreak(string A, vector<string> &B) 
{
    //code here
    int n = A.size();
    unordered_set<string> st(B.begin(), B.end());
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(dp[j-1] && st.find(A.substr(j-1, i-j+1)) != st.end())
            {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}