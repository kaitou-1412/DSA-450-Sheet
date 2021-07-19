//Function to merge k sorted arrays.
struct Triplet
{
    int value, arrayIndex, indexInArray;
    Triplet(int x, int y, int z)
    {
        value = x;
        arrayIndex = y;
        indexInArray = z;
    }
};

struct customComp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.value > t2.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> v;
    priority_queue<Triplet, vector<Triplet>, customComp> pq;
    
    for(int i=0; i<k; i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    
    while(!pq.empty())
    {
        Triplet t = pq.top();
        pq.pop();
        v.push_back(t.value);
        int arrayIndex = t.arrayIndex;
        int indexInArray = t.indexInArray;
        if(indexInArray+1 < k)
        {
            Triplet t(arr[arrayIndex][indexInArray+1], arrayIndex, indexInArray+1);
            pq.push(t);
        }
    }
    return v;
}