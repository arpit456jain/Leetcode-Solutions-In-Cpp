class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            cout<<start<<" ";
            ans = ans^start;
            start+=2;
        }
        return ans;
    }
};