#include<stdio.h>
int removeElement(int* nums, int numsSize, int val);
int main()
{
	
	int nums[] = {0,1,2,2,3,0,4,2};
    int size = removeElement(&nums, 8, 2);
    int i;
    for (i = 0;i < size;i++)
    {
        printf("%d",nums[i]);
    }
    return 0;
}
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int k = 0;
    for (i;i < numsSize;i++)
    {
        if (nums[i] == val)
        {
            k++;
        }
        else
        {
            nums[i - k] = nums[i];
        }
    }
    return numsSize - k;
}