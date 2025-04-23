class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        int i=0;
        //去算每個人有幾次可以做
        while(i<colors.size()-1){
            int same=1;
            while(i<colors.size()-1&&colors[i]==colors[i+1]&&colors[i]=='A'){
                i++;
                same++;
                while(same>=3){
                    alice++;
                    same--;
                }
            }
            same=1;
            while(i<colors.size()-1&&colors[i]==colors[i+1]&&colors[i]=='B'){
                i++;
                same++;
                while(same>=3){
                    bob++;
                    same--;
                }
            }
            same=1;
            i++;
        }
        if(alice==0&&bob==0){
            return false;
        }
        return alice>bob?true:false;
    }
};