class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetTime=times[targetFriend][0];
        sort(times.begin(),times.end());
        vector<int>chairTime(times.size());//char[i]何時free
        for(int i=0;i<times.size();i++){//friend
            for(int j=0;j<times.size();j++){//chair
                if(chairTime[j]<=times[i][0]){
                    chairTime[j]=times[i][1];
                    if(times[i][0]==targetTime){
                        return j;
                    }
                    break;
                }
            }
        }
        return 0;
    }
};