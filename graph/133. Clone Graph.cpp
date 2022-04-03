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
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node->neighbors.size()==0)  return new Node(node->val);
        
        // Node* clone = new Node(1);
        
        unordered_map<Node*,Node*> m;
        queue<Node*> q;
        
        q.push(node);
        m[node] = new Node(node->val);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for(Node* n:curr->neighbors) {
                if(m.find(n) == m.end()) { // found in map 
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[curr]->neighbors.push_back(m[n]);
            }
        }
        
        return m[node];
    }
};