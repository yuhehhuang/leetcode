/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
         vector<vector<int>>result;
        if(root!=NULL){
            que.push(root);
        }
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                Node* tmp=que.front();
                que.pop();
                vec.push_back(tmp->val);
                for(int j=0;j<tmp->children.size();j++){
                    if(tmp->children[j]){
                        que.push(tmp->children[j]);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};