//Palindrome String
//User function Template for C
int isPlaindrome(char S[])
{
    int len = 0, i = 0;
    while (S[i] != '\0')
        i++, len++;
    int result = 1;
    for (int i = 0; i < len / 2; i++)
    {
        if (S[i] != S[len - i - 1])
        {
            result = 0;
            break;
        }
    }
    return result;
}