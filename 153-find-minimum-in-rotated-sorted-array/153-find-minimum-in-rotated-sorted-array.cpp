class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
       int l=0;
        int r = n-1;
        if(n == 1)
            return nums[0];
        if(nums[l]<=nums[r])
            return nums[l];
        
        int mid;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(mid-1>=0 and mid+1<n)
            {
                if(nums[mid] <= nums[mid - 1] and nums[mid] <= nums[mid+1] )
                return nums[mid];
            
            }
                if(nums[mid] > nums[mid + 1])
                    return nums[mid + 1];
                else if(nums[mid] >= nums[l]) // left is sorted move to  right
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }

            
        }
        return -1; 
    }
};