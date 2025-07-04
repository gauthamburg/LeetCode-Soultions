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
    unordered_map<Node*,Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        if(mp[node])return mp[node];

        Node* clone=new Node(node->val);
        mp[node]=clone;

        for(Node* nodey:node->neighbors){
            clone->neighbors.push_back(cloneGraph(nodey));
        }

        return clone;
    }
};