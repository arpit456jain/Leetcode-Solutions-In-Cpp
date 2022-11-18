class Solution {
public:
    int nthUglyNumber(int n) {
        long long int ans;
        int count=0;
        map<long long int,int> m;
        priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
        pq.push(1);
        while(count<n)
        {
            ans = pq.top();
            // cout<<ans<<" ";
            if(m.find(2*ans)==m.end())
            {
                pq.push(2*ans);  
                m[2*ans]=1;
            }
            if(m.find(3*ans)==m.end())
            {
                pq.push(3*ans);    
                m[3*ans]=1;
            }
            if(m.find(5*ans)==m.end())
            {
                pq.push(5*ans);    
                m[5*ans]=1;
            }
            
            
            
            pq.pop();
            
            count++;
        }
        
        return ans;
    }
};