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