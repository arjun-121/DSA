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
        if (!node ) 
            return node;
        map<Node*, bool> visited;
        queue<Node*> qu;
        map<int, vector<int> > newGp;
        map<int , Node*> newN;
        qu.push(node);
        visited.insert({node, true});
        // iterate over the queue
        while(!qu.empty()) {
            Node* temp = qu.front();
            qu.pop();

            

            if(newN.find(temp->val) == newN.end()) {
                    Node* newNode = new Node(temp -> val);
                    newN.insert({temp -> val, newNode});
                }



            vector<Node*> locals = temp->neighbors;
            if(!locals.size())
                return newN[temp->val];
            
            vector<int> Neighbor;

            for(int i= 0; i< locals.size(); i++) {
                Node* neigh = locals[i];
                Neighbor.push_back(neigh -> val);
                // push to queue if not visited
                if(visited.find(neigh) == visited.end()) {
                    visited.insert({neigh, true});
                    qu.push(neigh);
                }

                if(newN.find(neigh->val) == newN.end()) {
                    Node* newNode = new Node(neigh -> val);
                    newN.insert({neigh -> val, newNode});
                }
            }

            newGp.insert({temp -> val, Neighbor});
            
        }
        // after iterating over the queue
        Node* ans;
        for(auto it : newGp) {
            int val = it.first;
            vector<int> nbrs = it.second;

            for(int i = 0; i< nbrs.size(); i++ ) {
                Node* currNode = newN[val];
                if(val == 1)
                    ans = currNode;
                Node* nbrNode = newN[nbrs[i]];
                currNode->neighbors.push_back(nbrNode);
            }
        }
        return ans;
    }
};