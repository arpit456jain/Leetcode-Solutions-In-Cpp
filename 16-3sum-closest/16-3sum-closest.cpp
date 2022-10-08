class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int dif = INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int first = nums[i];
            int start = i+1;
            int end = nums.size()-1;
            
            while(start<end)
            {
                int sum = first + nums[start] + nums[end];
                if(abs(sum - target)==0)
                    return target;
                else if(abs(sum - target) < dif)
                {
                    dif = abs(sum-target);
                    ans = sum;
                }
                
                if(sum > target)
                    end--;
                else
                    start++;
                
            }
        }
        
        return ans;
    }
};