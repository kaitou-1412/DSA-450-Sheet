vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
{
    unordered_map<int, int> heads;
    unordered_map<int, pair<int, int>> mp;
    for(int i=0;i<p;i++){
        if(heads.find(a[i])==heads.end()) heads[a[i]]=1;
        
        heads[b[i]]=-1;
        
        mp[a[i]] = {b[i], d[i]};
    }
    
    
    vector<vector<int>> res;
    for(auto i:heads)
    {
        if(i.second==1)
        {
            int tank, tap, minD=INT_MAX;
            tank = i.first;
            int lastHome=i.first;
            while(true)
            {
                auto next = mp.find(lastHome);
                if(next==mp.end()) break;
                
                minD = min(minD, next->second.second);
                lastHome = next->second.first;
            }
            tap = lastHome;
            
            res.push_back({tank, tap, minD});
        }
    }
    sort(res.begin(), res.end());
    return res;
}