class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>R_team;
        queue<int>D_team;
        int n=senate.size();
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                R_team.push(i);
            }
            else{
                D_team.push(i);
            }
        }
        while(!R_team.empty()&&!D_team.empty()){
            if(R_team.front()<D_team.front()){
                R_team.push(n++);
            }
            else{
                D_team.push(n++);
            }
            R_team.pop();
            D_team.pop();
        }
        return R_team.empty()?"Dire":"Radiant";
    }
};