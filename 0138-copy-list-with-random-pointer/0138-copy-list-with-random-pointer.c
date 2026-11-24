/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node *origin[1001];
    struct Node *copy[1001];
    int cnt=0;
    struct Node* cur = head;
    while(cur){
        struct Node* unit = malloc(sizeof(struct Node));
        unit->val = cur->val;
        unit ->next=NULL;
        unit->random=NULL;
        origin[cnt] = cur;
        copy[cnt] = unit;
        cur=cur->next;
        cnt++;
    }
    for(int i=0;i<cnt;++i){
        if(i+1<cnt){
            copy[i]->next = copy[i+1];
        }
        else{
            copy[i]->next = NULL;
        }

        if(origin[i]->random==NULL){
            copy[i]->random==NULL;
        }
        else{
            for(int j=0;j<cnt;j++){
                if(origin[j]==origin[i]->random){
                    copy[i]->random = copy[j];
                    break;
                }
            }
        }
    }
    return copy[0];
}