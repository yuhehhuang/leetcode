

char * mergeAlternately(char * word1, char * word2){
    char *ans = (char *)calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));
    int index1=0;
    int index2=0;
    int indexmer=0;
    while(index1<strlen(word1)||index2<strlen(word2)){
        if(index1<strlen(word1)){
            ans[indexmer]=word1[index1];
            indexmer++;
            index1++;
        }
        if(index2<strlen(word2)){
            ans[indexmer]=word2[index2];
            indexmer++;
            index2++;
        }
    }
    return ans;

}