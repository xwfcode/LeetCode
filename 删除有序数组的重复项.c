#include<stdio.h>
int removeDuplicates(int* nums, int numsSize);
int main()
{
	
	int nums[] = {1,1,1};
    int size = removeDuplicates(&nums, 3);
    int i;
    for (i = 0;i < size;i++)
    {
        printf("%d",nums[i]);
    }
    return 0;
}
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int j = 1;
    while (j < numsSize)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            nums[i+1] = nums[j];
            i++;
            j++;
        }
    }
    return(i + 1);
}