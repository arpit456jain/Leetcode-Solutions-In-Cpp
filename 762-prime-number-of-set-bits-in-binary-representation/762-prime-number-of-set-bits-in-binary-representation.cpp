class Solution {
public:
    int countPrimeSetBits(int left, int right) {
       map<int,int> m;
        m[2] = 1;
        m[3] = 1;
        m[5] = 1;
        m[7] = 1;
        m[11] = 1;
        m[13] = 1;
        m[17] = 1;
        m[19] = 1;
        m[23] = 1;
        m[29] = 1;
        m[31] = 1;
        int count = 0;
        for(int i = left;i<=right;i++)
        {
            int val = __builtin_popcount(i);
            if(m.find(val) != m.end())
                count++;
        }
        return count;
    }
};