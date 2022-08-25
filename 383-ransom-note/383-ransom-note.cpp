class Solution {
public:
    void populate(string cur,map<char,int> &m)
    {
        for(auto i : cur)
            m[i]+=1;
    }
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m1;
        map<char,int> m2;
        populate(ransomNote,m1);
        populate(magazine,m2);
//         for(auto i : m1)
//             cout<<i.first<<" "<<i.second<<"\n";
        
//         for(auto i : m2)
//             cout<<i.first<<" "<<i.second<<"\n";
        for(auto i : m1)
        {
            char cur = i.first;
            int freq = i.second;
            if(m2.find(cur) == m2.end() or m2[cur]<freq)
                return false;
        }
        return true;
    }
};