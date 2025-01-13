class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        //撞在一起時誰多誰先，若相同則Alice first
        int left=0;
        int right=plants.size()-1;
        int cnt=0;
        int A_max=capacityA;
        int B_max=capacityB;
        while(left<right){
            if(plants[left]>capacityA){
                cnt++;
                capacityA=A_max;
            }
            capacityA-=plants[left++];
            if(plants[right]>capacityB){
                cnt++;
                capacityB=B_max;
            }
            capacityB-=plants[right--];
        }
        if(left==right){
            if(plants[left]>capacityA&&plants[left]>capacityB){
                cnt+=1;
            }
        }
        return cnt;
    }
};