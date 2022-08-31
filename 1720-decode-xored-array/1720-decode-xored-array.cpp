class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> ans;
        for(auto i : encoded)
        {
            ans.push_back(first);
            first = first ^ i;
        }
        
        ans.push_back(first);
        return ans;
    }
};