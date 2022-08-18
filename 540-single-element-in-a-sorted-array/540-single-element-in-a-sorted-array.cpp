class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       int i=0;
        int n = nums.size()-1;
        
        while(i<n)
        {
            if(nums[i]!=nums[i+1])
                return nums[i];
            i=i+2;
        }
        
        return nums[n];
    }
    int findelement(vector<int> nums,int s,int e)
    {
        if(s>e)
            return -1;
        int mid = (s + e)/2;
        cout<<mid<<"\n";
        if(nums[mid] != nums[mid-1] and nums[mid]!= nums[mid+1])
            return nums[mid];
        
        int a,b;
        if(nums[mid] == nums[mid - 1])
        {
            a = findelement(nums,s,mid-2);
            b = findelement(nums,mid+1,e);
        }
            
        else if(nums[mid] == nums[mid + 1])
        {
                a = findelement(nums,s,mid - 1);
                a = findelement(nums,mid + 2,e);
        }
        
        if(a==-1)
            return b;
        else
            return a;
        
    }
};