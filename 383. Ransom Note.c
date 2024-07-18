#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int len1 = strlen(ransomNote);
    int len2 = strlen(magazine);
    int arr1[26]={0};
    for(int i=0;i<len2;i++){
        arr1[magazine[i]-'a']++;
    }
    
    for(int i=0;i<len1;i++){
        if(arr1[ransomNote[i]-'a']==0){
           return false;
        }
        arr1[ransomNote[i]-'a']--;
    }
    
    return true;
}

int main() {
    printf("%d\n", canConstruct("a", "b")); // Output: 0 (false)
    printf("%d\n", canConstruct("aa", "ab")); // Output: 0 (false)
    printf("%d\n", canConstruct("aa", "aab")); // Output: 1 (true)
    return 0;
}
