class Solution {
public:
    int search2(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            // first check which part is sorted 
            
            // left part sorted
            if(nums[mid] >= nums[l])
            {
                if(target>=nums[l] and target<=nums[mid])
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            else // right part sorted
            {
                if(target>=nums[mid] and target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
                
            }
        }
        
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        set<int> s;
        for(auto i : nums)
            s.insert(i);
        
        nums = {};
        for(auto i : s)
            nums.push_back(i);
        if(search2(nums,target) == -1)
            return false;
        else
            return true;
    }
};