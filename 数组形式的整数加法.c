/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //只能模拟手工加法，不能全加起来再来放
#include<stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int k1 = k;
    int kSize = 1;//用来获取k的位数
    while ((k1 / 10) > 0)
    {
        kSize++;
        k1 = k1 / 10;
    }
    int len = kSize > numSize ? kSize : numSize;
    int length = len + 1;
    int* result = (int*)malloc(sizeof(int) * length);//用来存放新的数组
    if (result == NULL) {  // 检查是否分配成功
        *returnSize = 0;   // 返回长度为0表示失败
        return NULL;       // 返回NULL指针
    }
    int Ai = numSize - 1;
    int k2 = k;
    int Ri = 0;//记录结果数组的下标
    int next = 0;//记录是否需要进位
    int temp;
    int z = 1;
    while (((len>0)||(next==1)))
    {
        if(Ai>=0)
        {
            temp = num[Ai] + (k2 % 10) + next;
            if (temp <= 9)
            {
                result[Ri] = temp;
                next = 0;
            }
            else
            {
                result[Ri] = (temp % 10);
                next = 1;
            }
        }
         else
            {
                result[length - 1] = 1;
                next = 0;
                z--;
            }
        
        k2 = k2 / 10;
        len--;
        Ai--;
        Ri++;
    }
    int j = length - 1 - z;
    int i = 0;
    int tmp;
    while(i<j)
    {
        tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
        j--;
        i++;

    }
    *returnSize = length - z;
    return result;
}