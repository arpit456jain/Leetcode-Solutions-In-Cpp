class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        map<int,int> m2;
        
        for(auto i : arr)
            m[i]++;
        
        for(auto i : m)
        {
            if(m2.find(i.second) != m2.end())
                return false;
            m2[i.second]=1;
        }
        
        return true;
    }
};