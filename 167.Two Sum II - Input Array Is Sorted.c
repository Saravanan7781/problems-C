void func(int* nums,int start,int end,int target){
    if(start<end){
         if(nums[start]+nums[end]==target){
            nums[0]=start+1;
            nums[1]=end+1;
         }
          else if(nums[start]+nums[end]<target){
            return func(nums,start+1,end,target);
          }
          else if(nums[start]+nums[end]>target){
            return func(nums,start,end-1,target);
          }
    }
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    func(numbers,0,numbersSize-1,target);

    *returnSize = 2;
    return numbers;
}
