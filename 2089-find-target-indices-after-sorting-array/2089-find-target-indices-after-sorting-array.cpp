class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<int> tmp = searchRange(nums,target);
        int s = tmp[0];
        int l = tmp[1];
        vector<int> ans;
        if(s == -1 and l == -1)
            return {};
        for(int i=s;i<=l;i++)
            ans.push_back(i);
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        if(nums.size() == 0)
            return {-1,-1};
        ans[0] = findFirstPos(nums,target);
        ans[1] = findLastPos(nums,target);
        
        return ans;
    }
    
    int findFirstPos(vector<int>& nums, int target)
    {
        int mid;
        int l=0;
        int r = nums.size()-1;
        int ans = -1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                r = mid - 1;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return ans;
    }
    int findLastPos(vector<int>& nums, int target)
    {
        
        int mid;
        int l=0;
        int ans=-1;
        int r = nums.size() - 1;
        
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return ans;
    }
};