class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int val=(skill[0]+skill[skill.size()-1])/2;
        long long sum=0;
        for(int i=0;i<skill.size()/2;i++){
            if((skill[i]+skill[skill.size()-1-i])/2!=val){
                return -1;
            }
            sum+=skill[i]*skill[skill.size()-1-i];
        }
        return sum;

    }
};