class Solution {
public:
   static bool cmp(int a,int b)
   {
       if(a>b)
           return true;
       else
           return false;
   }
    
    int findsmallest(vector<int> &v,int k)
    {
        cout<<k<<"\n";
        for(auto i : v)
            cout<<i<<" ";
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(k <= 0)
                break;
            ans++;
            k = k - v[i];
        }
        
        return ans;
    }
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        for(auto i : arr)
            m[i]+=1;
        
       vector<int> p;
        
        for(auto i : m)
            p.push_back(i.second);
        sort(p.begin(),p.end(),cmp);
        return findsmallest(p,n/2);
    }
};