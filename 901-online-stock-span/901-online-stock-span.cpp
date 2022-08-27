class StockSpanner {
public:
    int i=0;
    stack<pair<int,int>> s;
    StockSpanner() {
        s={};
    }
    
    int next(int price) {
        int ans;
        while(!s.empty() and s.top().first <= price)
            s.pop();
        
        if(s.empty())
           ans = i+1;
        else
        {
            int t  = s.top().second;
            ans = i - t;
        }
        // cout<<i+1<<"\n";
        s.push({price,i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */