#include <bits/stdc++.h>
using namespace std;
// check if result string is valid shuffle of string first and second
bool shuffleCheck(string first, string second, string result)
{

    // check length of result is same as
    // sum of result of first and second
    if (first.size() + second.size() != result.size())
    {
        return false;
    }
    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.size())
    {

        // check if first character of result matches with first character of first string
        if (i < first.size() && first[i] == result[k])
            i++;

        // check if first character of result matches the first character of second string
        else if (j < second.size() && second[j] == result[k])
            j++;

        // if the character doesn't match
        else
        {
            return false;
        }

        // access next character of result
        k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if (i < first.size() || j < second.size())
    {
        return false;
    }

    return true;
}


int main()
{

    string first = "XY";
    string second = "12";
    string results[] = {"1XY2", "Y12X"};
    int len = sizeof(results)/sizeof(results[0]);
    // call the method to check if result string is
    // shuffle of the string first and second
    for (int i = 0; i<len; i++)
    {
        string result = results[i];
        if (shuffleCheck(first, second, result) == true)
            cout << result << " is a valid shuffle of " << first << " and " << second << "\n";
        else
            cout << result << " is not a valid shuffle of " << first << " and " << second << "\n";
    }

    return 0;
}
