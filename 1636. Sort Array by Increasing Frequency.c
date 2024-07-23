struct Element{
    int number;
    int freq;
};

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int count[201]={0};
    int* result = (int *)malloc(numsSize * sizeof(int));
    for(int i=0;i<numsSize;i++){
        count[nums[i]+100]++;
    }


    struct Element ele[numsSize];
    int index =0;
    for(int i=0;i<numsSize;i++){
        if(count[nums[i] + 100]>0){
            ele[index].freq = count[nums[i]  + 100];
            ele[index].number = nums[i];
            index++;
            count[nums[i]+100] = 0;
        }
    }


    

    for(int i=0;i<index-1;i++){
        for(int j=0;j<index-i-1;j++){
            if(((ele[j+1].freq < ele[j].freq) || (ele[j].freq == ele[j+1].freq && ele[j+1].number>ele[j].number) )){
                struct Element temp = ele[j+1];
                ele[j+1] = ele[j];
                ele[j] = temp;

            }
        }
    }
    int ind=0;

    for(int i=0;i<index;i++){
        while(ele[i].freq>0){
        result[ind]=ele[i].number;
        ind++;
        ele[i].freq--;
        }
    }
    for(int i=0;i<index;i++){
        while(ele[i].freq>0){
        printf("%d ",ele[i].number);
        ele[i].freq--;
        }
    }

    *returnSize = numsSize;

    return result;
}
