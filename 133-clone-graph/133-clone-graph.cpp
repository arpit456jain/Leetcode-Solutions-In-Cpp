/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node* , Node*>s; 
    Node* cloneGraph(Node* node) {
     if(node == NULL) 
     return NULL;
       
 if(s.find(node) ==s.end()) // if not present in map
   {   
       // make a copy
      s[node] = new Node(node -> val);
      
      // travel in adjacency list and add copy
      for(auto u: node -> neighbors) 
          s[node] -> neighbors.push_back(cloneGraph(u)); 
 }
      return s[node];   
   
    }
};