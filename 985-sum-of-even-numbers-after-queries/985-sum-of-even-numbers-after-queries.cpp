class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
     
        int sum1=0;
        for(auto i : nums)
        {
            if(i%2==0)
            sum1+=i;
        }
        
        vector<int> ans;
        for(auto i : queries)
        {
            int val = i[0];
            int idx = i[1];
            if(nums[idx]%2==0)
                sum1-=nums[idx];
            nums[idx]+=val;
            
            if(nums[idx]%2==0)
                sum1+=nums[idx];
            
            ans.push_back(sum1);
            
        }
        
        return ans;
    }
};