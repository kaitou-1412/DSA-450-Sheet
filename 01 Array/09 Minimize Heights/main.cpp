#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//while(str.length()==0) getline(cin, str);
//str = "";
using namespace std;
#define lli long long int
#define ull unsigned long long int
#define fo(i, start, ending) for(i=start;i<ending;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define rtr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
typedef pair<int, int> pii;
typedef pair<lli, lli> pl;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void ip(int a[], int n)
{
    int i;
    fo(i, 0, n) cin >> a[i];
}

void op(int a[], int n)
{
    int i, start = 0, ending = n-1;
    fo(i, start, ending) cout << a[i] << " ";
    cout << a[ending] << "\n";
}

int getMinDiff(int arr[], int n, int k) 
{
    // code here
    sort(arr,arr+n);
    int ans = arr[n-1]-arr[0];
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]>=k)
        {
            int currMin = min(arr[i+1]-k, arr[0]+k);
            int currMax = max(arr[i]+k, arr[n-1]-k);
            ans = min(ans, currMax-currMin);
        }
    }
    return ans;
}

int getMinDiff(int arr[], int n, int k)
{
    vector<pair<int, int>> v;
    vector<int> taken(n);

    // we will store all possible heights in a vector
    for(int i = 0; i < n; i++){
        if(arr[i] - k >= 0){
            v.push_back({arr[i] - k, i});
        }
        v.push_back({arr[i] + k, i});
    }
    sort(v.begin(), v.end());
    int elements_in_range = 0;
    int left = 0;
    int right = 0;

    // By two pointer we will traverse v and whenever we will get a range
    // in which all towers are included, we will update the answer.
    while(elements_in_range < n && right < v.size()){
        if(taken[v[right].second] == 0){
            elements_in_range++;
        }
        taken[v[right].second]++;
        right++;
    }
    int ans = v[right - 1].first - v[left].first;
    while(right < v.size()){
        if(taken[v[left].second] == 1){
            elements_in_range--;
        }
        taken[v[left].second]--;
        left++;

        while(elements_in_range < n && right < v.size()){
            if(taken[v[right].second]==0){
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }

        if(elements_in_range == n){
            ans = min(ans, v[right - 1].first - v[left].first);
        }
        else{
            break;
        }
    }
    return ans;
}

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    int a[n];
    ip(a, n);
    cout <<  getMinDiff(a, n, k) << "\n";
    return 0;
}
