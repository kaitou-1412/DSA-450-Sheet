#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void dfs(long long int src, vector<long long int> &vis, vector<long long int> g[], long long int &counter)
{
    vis[src] = 1;
    counter++;
    for (auto x : g[src])
    {
        if (!vis[x])
        {
            dfs(x, vis, g, counter);
        }
    }
}

long long int journeyToMoon(long long int n, vector<vector<long long int>> astronaut)
{
    long long int e = astronaut.size();
    vector<long long int> g[n];
    for (long long int i = 0; i < e; i++)
    {
        g[astronaut[i][0]].push_back(astronaut[i][1]);
        g[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    vector<long long int> country;
    vector<long long int> vis(n, 0);
    for (long long int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            long long int counter = 0;
            dfs(i, vis, g, counter);
            country.push_back(counter);
        }
    }
    long long int N = country.size();
    long long int res = n * (n - 1) / 2;
    for (long long int i = 0; i < N; i++)
    {
        res -= country[i] * (country[i] - 1) / 2;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long long int n = stoll(first_multiple_input[0]);

    long long int p = stoll(first_multiple_input[1]);

    vector<vector<long long int>> astronaut(p);

    for (long long int i = 0; i < p; i++)
    {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (long long int j = 0; j < 2; j++)
        {
            long long int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}