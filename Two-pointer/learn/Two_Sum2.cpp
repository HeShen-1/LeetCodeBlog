#include "pch.h"

/*
    针对有序且有解的数组，使用双指针一定可以遍历到最优解。
    对于两数之和，左右两端两个指针，如果两个指针之和小于目标值，说明应该增大两个指针之和，
    由于数组是递增的，所以移动左指针，如果大于目标值则移动右指针，否则输出结果
*/


vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum;

    while (l < r)
    {
        sum = numbers[l] + numbers[r];
        if (sum == target)
        {
            break;
        }
        if (sum < target)
        {
            /* code */
            ++l;
        }
        else
        {
            --r;
        }
    }
    return vector<int>{l + 1, r + 1};
}


int main() {
    int target = 9;
    vector<int> a = {2, 7, 11, 15};
    vector<int> ans = twoSum(a, target);
    for (int i = 0; i < ans.size(); i++)
    {
        /* code */
        cout << ans[i] << " ";
    }
    
}
