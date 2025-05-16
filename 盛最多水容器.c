//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。

//法一：暴力解法时间复杂度为O(n*2)
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

//法二：双指针时间复杂度为O(n)
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize -1;
    int x;
    int max = 0;
    int sum ;
    while(left != right)
    {
        x = right - left;
        if(height[left] <= height[right])
        {
            sum = x * height[left];
            left++;
        }
        else 
        {
            sum = x * height[right];
            right--;
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}