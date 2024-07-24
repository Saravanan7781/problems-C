int pivotIndex(int* nums, int numsSize) {  
    int leftSum=0;
    int totalSum=0;
    int currentSum=0;
    for(int i=0;i<numsSize;i++){
        totalSum+=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        printf("%d:%d\n",currentSum,(totalSum-nums[i]-currentSum));
        if(currentSum==(totalSum-nums[i]-currentSum)){
            return i;
        }
        currentSum+=nums[i];
    }

    return -1;
}
