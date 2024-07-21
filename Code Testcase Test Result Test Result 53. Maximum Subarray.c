int maxSubArray(int* nums, int numsSize) {
    int currentMax = nums[0];
    int globalMax = nums[0];
    if(numsSize==2){
       if(nums[0]>0 && nums[1]>0){
        return nums[0]+nums[1];
       }
       else{
        if(nums[0]>0 && nums[1]<0){
            return nums[0];
        }
        else if(nums[0]<0 && nums[1]>0){
            return nums[1];
        }

        else{
            return (nums[0]<nums[1])?nums[1]:nums[0];
        }
       }
        
    }
    for(int i=1;i<numsSize;i++){
        currentMax = (nums[i]>currentMax + nums[i])?nums[i]:(nums[i]+currentMax);
        if(currentMax>globalMax){
            globalMax = currentMax;
        }
    }

    

    return globalMax;
}
