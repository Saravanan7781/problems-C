int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int lastIndex[256];
    int start=0;
    memset(lastIndex,-1,sizeof(lastIndex));
    int maxLength =0;
    for(int i=0;i<n;i++){
        if(lastIndex[s[i]]>=start){
            start = lastIndex[s[i]] +1; printf("%d\n",start);
        }                    
        lastIndex[s[i]]=i;
        maxLength = (i-start+1)>maxLength?(i-start+1):maxLength;
       
    }

    return maxLength;
}
