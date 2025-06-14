/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //考虑二进制
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int ret = 0;
    for(int i = 0; i < numsSize; i++)
    {
        ret = ret ^ nums[i];
    }
    //数组中所有的数异或，那么出现两次的都异或没了
    //ret 最后的值 == x1 ^ x2
    //下一步想办法分离出x1，x2
    //ret二进制的数里面肯定有含1的位

    int m = 0;//假设第m为是其中的任意一个1
    //找出ret为1的位置
    while(m < 32)
    {
        if(ret & (1u<<m))
            break;
        else
            m++;
    }
    int x1 = 0,x2 = 0;
    //这里分成两个组，一个组里面有x1和其他两个重复数字，第二个组里面有x2和其他的两个重复数字
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] & (1u<<m))//一个值与1的左移m位，就可以得到这个值的m位为1还是为0
        {
            x1 = x1 ^ nums[i];
        }
        else 
        x2 = x2 ^ nums[i];
    }
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = x1;
    ans[1] = x2;
    *returnSize = 2;
    return ans;
}
