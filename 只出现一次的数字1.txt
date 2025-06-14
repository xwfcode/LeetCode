int singleNumber(int* nums, int numsSize) {
    //异或（异或具有交换律和结合律，
    //任何数和0做异或运算，任是本身，
    //任何数和自身做异或结果是0），
    //所有的元素都进行异或，最终结果就只会是那个只出现过一次的数字
    int result = 0;
    for(int i = 0; i < numsSize; i++)
    {
        result = result ^ nums[i];
    }
    return result;
}