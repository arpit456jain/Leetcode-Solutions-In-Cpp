class Solution {
public:
    bool divideArray(vector<int>& nums) {
       map<int,int> m;
        for(auto i : nums)
        m[i]+=1;
        
        for(auto i : m)
            if(i.second % 2 == 1)
                return false;
        return true;
    }
};