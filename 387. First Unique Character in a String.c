#include <stdio.h>
#include<string.h>


int firstUniqChar(char* s) {
    int len = strlen(s);
    int result =0;
    if(strlen(s)==1){
        return 0;
    }
    for(int i=0;i<len;i++){
        result = 0;
        for(int j=0;j<len;j++){
            if(i==j)
            continue;
            if(s[i]==s[j]){
            result = 1;
            break;
            }
        }
        if(result==0)
        return i;
    }
    return -1;
    
}

int main()
{
    char chara[] = "leetcode";
    printf("index at:%d",firstUniqChar(chara));

    return 0;
}
