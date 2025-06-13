#include "pch.h"

int minimizeMax(vector<int> &nums, int p)
{
    // 对输入的向量 nums 进行排序，以便后续计算相邻元素的差值
    sort(nums.begin(), nums.end());

    // 定义一个lambda函数 check，用于检查是否能找到 p 对元素，使得每对元素的差值不超过 mx
    auto check = [&](int mx) -> bool
    {
        int cnt = 0; // 初始化计数器，用于记录满足条件的元素对数量
        // 遍历向量 nums，检查相邻元素的差值
        for (int i = 0; i + 1 < nums.size(); i++)
        {
            // 如果当前相邻元素的差值不超过 mx
            if (nums[i + 1] - nums[i] <= mx)
            {
                cnt++; // 满足条件的元素对数量加1
                i++;   // 跳过下一个元素，避免重复使用
            }
        }
        // 如果满足条件的元素对数量不少于 p，则返回 true，否则返回 false
        return cnt >= p;
    };

    // 初始化二分查找的左右边界
    int left = -1, right = nums.back() - nums[0];
    // 二分查找的循环条件，当左边界加1小于右边界时继续循环
    while (left + 1 < right)
    {
        // 计算中间值，避免整数溢出
        int mid = left + (right - left) / 2;
        // 如果中间值满足 check 函数的条件，则更新右边界，否则更新左边界
        (check(mid) ? right : left) = mid;
    }
    // 返回最终的结果，即满足条件的最小的最大值
    return right;
}

int main()
{
    vector<int> a = {10, 1, 2, 7, 1, 3};
    int p = 2;

    cout << minimizeMax(a, p);

}