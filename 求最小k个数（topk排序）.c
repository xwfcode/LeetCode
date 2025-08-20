/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //思路：建立一个大小为k的堆，题目中是要求出最小的k个数，就建立一个大根堆，
 //然后再用数组其余的数与大根堆的堆顶进行对比，如果小于对堆顶元素则替换掉，然后再进行向下调整
void  AdjustDown(int *a ,int n,int root);
void HeapInit(int* a,int k);
void Swap(int *a,int *b);
int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
    if(k <= 0 || arrSize <= 0)
    {
        *returnSize = 0;
        return (int*)malloc(0);
    }
    if(k>arrSize)
    {
        k = arrSize;
    }

    HeapInit(arr,k);
    for(int i = k; i < arrSize;i++)
    {
        if(arr[i] < arr[0])
        {
            Swap(&arr[i],&arr[0]);
            AdjustDown(arr,k,0);
        }
    }
    //拷贝结果（任意顺序）
    //int *res =(int*)malloc(sizeof(int) * k);
    int* res = (int*)malloc(sizeof(int) * k);
    memcpy(res,arr,sizeof(int) * k);
    *returnSize = k;
    return res;
}

//构建堆
void HeapInit(int* a,int k)
{
    for(int i =(k - 1 - 1) / 2; i >= 0 ;i--)
    {
        AdjustDown(a,k,i);
    }
}
//向下调整函数
void  AdjustDown(int *a ,int n,int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while(child < n)
    {
        if (child + 1 < n && a[child + 1] < a[child])
        {
            child = child + 1;
        }
        if(a[parent] < a[child])
        {
            Swap(&a[parent],&a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

//调换函数
void Swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}