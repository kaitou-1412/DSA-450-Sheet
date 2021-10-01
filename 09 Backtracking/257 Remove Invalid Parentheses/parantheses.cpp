int openRemCnt, closeRemCnt;
vector<string> ans;
map<string, int> mp;
vector<string> removeInvalidParentheses(string s)
{
    int pair = 0;
    openRemCnt = closeRemCnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            pair++;
        else if (s[i] == ')')
        {
            if (pair > 0)
                pair--;
            else
                closeRemCnt++;
        }
    }
    openRemCnt = pair;
    ans.clear();
    string exp;
    recur(s, 0, 0, openRemCnt, closeRemCnt, exp);
    return ans;
}
void recur(string &s, int index, int pair, int openRemCnt, int closeRemCnt, string &exp)
{
    if (index == s.length())
    {
        if (openRemCnt == 0 and closeRemCnt == 0)
        {
            if (!mp[exp])
            {
                mp[exp] = true;
                ans.push_back(exp);
            }
        }
    }
    else
    {
        char c = s[index];
        bool openRemove = c == '(' && openRemCnt > 0;
        bool closeRemove = c == ')' && closeRemCnt > 0;
        if (openRemove)
            recur(s, index + 1, pair, openRemCnt - 1, closeRemCnt, exp);
        else if (closeRemove)
            recur(s, index + 1, pair, openRemCnt, closeRemCnt - 1, exp);
        exp += c;
        if (c != '(' && c != ')')
            recur(s, index + 1, pair, openRemCnt, closeRemCnt, exp);
        else
        {
            if (c == '(')
                recur(s, index + 1, pair + 1, openRemCnt, closeRemCnt, exp);
            else if (pair > 0)
                recur(s, index + 1, pair - 1, openRemCnt, closeRemCnt, exp);
        }
        exp.pop_back();
    }
}