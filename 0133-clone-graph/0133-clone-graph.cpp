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
    unordered_map<Node*,Node*>visited;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        Node* start=new Node(node->val);
        visited[node]=start;
        queue<Node*>que;
        que.push(node);
        while(!que.empty()){
            Node* tmp = que.front();
            que.pop();
            vector<Node*>nei_list=tmp->neighbors;
            for(int i=0;i<nei_list.size();++i){
                if(visited.find(nei_list[i])==visited.end()){
                    Node* clone=new Node(nei_list[i]->val);
                    visited[nei_list[i]]=clone;
                    que.push(nei_list[i]);
                }
                visited[tmp]->neighbors.push_back(visited[nei_list[i]]);
            }
        }
        return start;
    }
};