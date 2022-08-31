class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> s1;
        int c=0;
        for(auto i : allowed)
            s1[i]=1;
        
        for(auto i : words)
        {
            bool flag = true;
            for(auto j : i)
            {
                if(s1.find(j) == s1.end())
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                c++;
        }
                          
                    return c;
    }                   
};