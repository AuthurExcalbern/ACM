/* 1 Two Sum 2017-11-28

给一个数组和一个数字，要求在数组里找出相加等于目标数字的两个数
输出它们的序号

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

分析：可以暴力破解

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target) {
    int num_one, num_two;
    int* ans;
    ans = (int*)malloc(2 * sizeof(int));
    for(num_one = 0; num_one < numsSize; num_one++)
        for(num_two = num_one + 1; num_two < numsSize; num_two++)
        {
            if(nums[num_one] + nums[num_two] == target)
            {
                *ans = num_one;
                *(ans + 1) = num_two;
            }
        }
    
    return ans;
}
