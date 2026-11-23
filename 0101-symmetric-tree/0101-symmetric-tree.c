/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)return true;
    struct TreeNode*queue[3000];
    int front=0,rear=0;
    queue[rear++]=root->left;
    queue[rear++]=root->right;
    while(front<rear){
        struct TreeNode* node1= queue[front++];
        struct TreeNode* node2 = queue[front++];
        if(node1==NULL&&node2==NULL){
            continue;
        }
        if(node1==NULL||node2==NULL||node1->val!=node2->val){
            return false;
        }
        queue[rear++]=node1->left;
        queue[rear++]=node2->right;
        queue[rear++]=node1->right;
        queue[rear++]=node2->left;
    }
    return true;
}