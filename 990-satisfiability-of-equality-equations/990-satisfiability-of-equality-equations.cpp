class Solution {
public: 
    
    int find(int x,vector<int> &parent)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
 
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x],parent);
 
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
 
        return parent[x];
    }
 
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y,vector<int> &rank, vector<int> &parent)
    {
        // Find current sets of x and y
        int xset = find(x,parent);
        int yset = find(y,parent);
 
        // If they are already in same set
        if (xset == yset)
            return;
 
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
 
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
   static bool comp(const string &s1, const string &s2)
    {
        if(s1[1] == '=' and s2[1] == '!')
            return true;
        else
            return false;
    }
    bool equationsPossible(vector<string>& eq) {
        sort(eq.begin(),eq.end(),comp);
        
        // for(auto i : eq)
        //     cout<<i<<" ";
        
        vector<int> rank(100,0);
        vector<int> parent(100,0);
        
        for(int i=0;i<100;i++)
            parent[i] = i;
        
        
        // traverse the array
        for(auto i : eq)
        {
            int u = i[0] - 'a'; // finding int value of both chars
            int v = i[3] - 'a';
            
            // now we will apply union if its == else we will check if parent of u and v are equal
            if(i[1] == '=')
            {
                // make union
                Union(u,v,rank,parent);
            }
            else
            {
                if(find(u,parent) == find(v,parent))
                    return false;
            }
            
        }
        
        return true;
    }
};