class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
        int ans= 0;
        int mask=0;
        int n = arr.size();
        for(int i=30;i>=0;i--)
        {
            mask = mask | (1<<i);
            map<int,int> m;
            for(int j=0;j<n;j++)
            m[mask&arr[j]] = 1;
            
            int temp = ans|(1<<i);
            for(auto k : m)
            {
                if(m.find(k.first ^ temp) != m.end())
                {
                    ans = temp;
                break;
                }
            }
        }
        return ans;
    }
};