class Solution {
public:
    bool check(vector<int> arr,int k)
    {
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(auto i : arr)
            cout<<i<<" ";
        int n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] - arr[i+1] <= k)
            return true;
        }
        
            return false;
        
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
        
        for(auto i : m)
        {
            vector<int> ans = i.second;
            if(ans.size()>=2 and check(ans,k))
                return true;
        }
        
        // now the question is find if there is any element whose diff less than k
         
        return false;
        
    }
};