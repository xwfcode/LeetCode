//题目描述：给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序排列。




//法1用了中转数组空间复杂度为O(m+n)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    //p1,p2指向两个数组
    int p1 = 0;
    int p2 = 0;

    //定义存放临时数据的数组
    int arr[m + n];

    //定义中间变量
    int cur;
    while (p1 < m || p2 < n)
    {
        if (p1 == m) //p1已经遍历结束了，只要给p2剩余的项依次覆给cur就可以
        {
            cur = nums2[p2];
            p2++;
        }
        else if (p2 == n)//p2已经遍历结束了，只要给p1剩余的项依次覆给cur就可以
        {
            cur = nums1[p1];
            p1++;
        }
        else
        {
            if (nums1[p1] >= nums2[p2])
            {
                cur = nums2[p2];
                p2++;
            }
            else
            {
                cur = nums1[p1];
                p1++;
            }
            //nums1[p1] >= nums2[p2] ? cur = nums2[p2++] : cur = nums1[p1++];
        }
        arr[p1 + p2 - 1] = cur;
    }

    //开始复制数组
    for (int i = 0; i < m + n;i++)
    {
        nums1[i] = arr[i];
    }
}

//法二