int numberOfSpecialChars(char* word) {
    int len = strlen(word);
    int count =0;
  
  int lower[26]={0};
  int upper[26] ={0}; 
    for(int i=0;i<len;i++){
        if(word[i]>='a' && word[i]<='z'){
          
            lower[word[i]-'a']++;
        }
        else if(word[i]>='A' && word[i]<='Z'){
          
            upper[word[i]-'A']++;
        }
    }

    int i=0;
   while(i<26)
   {
        if(upper[i]>0 && lower[i]>0){
            count++;

        }
        i++;
    }

    return count;
}
