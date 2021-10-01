#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main()
{
    int t;
    cin >> t;
    int M[MAX][MAX];
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}

///Build Segment Tree
void buildTree(int *tree, int* a, int index, int s, int e)
{
    ///Base Case
    if(s>e) return;

    ///Base Case - Leaf Node
    if(s==e)
    {
        tree[index] = a[s];
        return;
    }

    ///Recursive Case
    int mid = (s+e)/2;
    ///Left SubTree
    buildTree(tree, a, 2*index, s, mid);
    ///Right SubTree
    buildTree(tree, a, 2*index+1, mid+1, e);

    int left = tree[2*index];
    int right = tree[2*index+1];

    tree[index] = min(left, right);
}

int histogram(vector<int> &nums)
{
    stack<int> s;
    int res = 0, i = 0, n = nums.size();

    while(i < n){
        if(s.empty() || nums[s.top()] <= nums[i])
            s.push(i++);
        else{
            int top = s.top();
            s.pop();
            int d = s.empty() ? i : i - s.top() - 1;
            res = max(res, nums[top] * d);
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int d = s.empty() ? i : i - s.top() - 1;
        res = max(res, nums[top] * d);
    }
    return res;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int res = 0;
    vector< vector<int> > A;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            v.push_back(M[i][j]);
        A.push_back(v);
        v.clear();
    }
    res = histogram(A[0]);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)
            A[i][j] = A[i][j] == 0 ? 0 : 1 + A[i - 1][j];
        res = max(res, histogram(A[i]));
    }
    return res;
}
