class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        //棉被放磁磚右端才有可能是最佳解
        sort(tiles.begin(),tiles.end(),cmp);
        int ans=0;
        int left=0;
        int cover=0;
        for(int i=0;i<tiles.size();++i){
            int tl=tiles[i][0];
            int tr=tiles[i][1];
            cover+=tr-tl+1;
            while(tiles[left][1]+carpetLen-1<tr){
                cover-=tiles[left][1]-tiles[left][0]+1;
                left++;
            }
            int uncover=max((tr-carpetLen+1)-tiles[left][0],0);
            ans=max(ans,cover-uncover);        
        }
        return ans;
    }
};