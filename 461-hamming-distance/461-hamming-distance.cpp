class Solution {
public:
    int setBits(int N) {
        // Write Your Code here
      
        int count=0;
        while(N!=0)
        {
           
           N = N&(N-1);
            count++;
            
            
        }
        
        return count;
    }
    int hammingDistance(int x, int y) {
        
        return setBits(x xor y);
    }
};