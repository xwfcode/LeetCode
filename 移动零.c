//题目描述：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
#include<stdio.h>
void moveZeroes(int* nums, int numsSize);
int main()
{
	int nums[] = {0,3,6,8,0,0,0,1,3,0};
    moveZeroes(nums, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", nums[i]);
    }
	return 0;
}

//法一：
void moveZeroes(int* nums, int numsSize) {
    int zero = 0;//标记最前面的0的下标
    for (int p = 0; p < numsSize; p++)
    {


        if (nums[p] != 0)
        {
            int temp = nums[zero];
            nums[zero] = nums[p];
            nums[p] = temp;
            zero++;
        }
    }
}

//法二：记录偏移量法
void moveZeroes(int* nums, int numsSize) {
    int offset = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
        {
            offset++;
        }
        else if(nums[i] != 0)
        {
            int temp;
            temp = nums[i-offset];
            nums[i-offset] = nums[i];
            nums[i] = temp;
        }
    }
}

//法三：不太会的方法
void moveZeroes(int* nums, int numsSize) {
    int l = 0;
    int r = 0;
    while(r < numsSize)
    {
        if(r == l || nums[r] == 0) //确保r在l的右边
        {
            r++;
        }
        else if(nums[l] != 0)
        {
            l++;
        }
        else //出现这个情况就是l走到了第一个零的下标，r走到了第一个零右边的第一个非零元素的下标
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
    }
}