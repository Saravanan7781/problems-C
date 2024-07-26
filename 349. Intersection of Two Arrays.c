void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bubbleSort(nums1,nums1Size);
    bubbleSort(nums2,nums2Size);

    int i=0;
    int j=0;
    int* result = (int *)malloc(nums1Size*sizeof(int));
    int count =0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            if(count==0 || result[count-1]!=nums1[i]){
                result[count++]=nums1[i];
            }
            i++;
            j++;
        }


    }
        *returnSize =count;
        return result;
}
