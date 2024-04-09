class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt=0;
        while(tickets[k]!=0){
            int i=0;
            while(i!=tickets.size()){
                if(tickets[i]!=0){
                    tickets[i]--;
                    cnt++;
                    //這很重要 避免我已經讓第k個已經=0 又繼續往後算其他的index直到尾端 這樣會有可能cnt又一直++到尾 會產生錯誤
                    if(tickets[k]==0){
                        break;
                    }
                }
                i++;
            }

        }
        return cnt;
    }
};
