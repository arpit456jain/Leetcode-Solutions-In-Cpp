class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v;
        
        for(auto i : arr)
        {
            int diff = abs(x - i);
            v.push_back({diff , i});
        }
        
        sort(v.begin(),v.end());
        
        // for(auto i : v)
        // {
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        
        vector<int> ans;
        
        for(auto i : v)
        {
            
            ans.push_back(i.second);
            k--;
            if(k==0)
                break;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};