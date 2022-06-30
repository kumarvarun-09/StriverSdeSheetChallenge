void heapifyDelete(vector<int> &v, int n, int i)
{
    // n is size
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && v[left] < v[smallest])
        smallest = left;
    if(right < n && v[right] < v[smallest])
        smallest = right;
    
    if(smallest != i)
    {
        swap(v[smallest], v[i]);
        heapifyDelete(v, n, smallest);
    }
}

void heapifyInsert(vector<int> &v, int n, int i)
{
    int parent = (i - 1) / 2;
    if(v[i] < v[parent])
    {
        swap(v[i], v[parent]);
        heapifyInsert(v, n, parent);
    }
}

void insertNode(vector<int> &v, int data)
{
    v.push_back(data);
    heapifyInsert(v, v.size(), v.size() - 1);
}

void deleteRoot(vector<int> &v)
{
    v[0] = v.back();
    v.pop_back();
    heapifyDelete(v, v.size(), 0);
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap, ans;
    for(int i = 0; i < n; i++)
    {
        if(q[i][0] == 0)
        {
            insertNode(heap, q[i][1]);
        }
        else if(heap.size())
        {
            ans.push_back(heap.front());
            deleteRoot(heap);
        }
    }
    return ans;
}
