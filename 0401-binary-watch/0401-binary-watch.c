/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int leds[10]={8,4,2,1,32,16,8,4,2,1};
 void backtrack(int idx,int count,int hour,int minute,char**ans,int*returnSize){
    if(hour>=12||minute>=60)return;
    if(count==0){
        ans[*returnSize]=(char*)malloc(sizeof(char)*6);
        sprintf(ans[*returnSize],"%d:%02d",hour,minute);
        (*returnSize)++;
        return;
    }
    for(int i=idx;i<10;++i){
        if(i<4){
            backtrack(i+1,count-1,hour+leds[i],minute,ans,returnSize);
        }
        else{
            backtrack(i+1,count-1,hour,minute+leds[i],ans,returnSize);
        }
    }
 }
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char**ans=(char**)malloc(sizeof(char*)*720);
    *returnSize=0;
    if(turnedOn>8 )return ans;
    backtrack(0,turnedOn,0,0,ans,returnSize);
    return ans;
}