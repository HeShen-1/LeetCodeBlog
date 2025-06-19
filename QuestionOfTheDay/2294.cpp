#include "pch.h"

int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int min = INT_MIN / 2;
    for (int x : nums) {
        if (x - min > k) {
            ans++;
            min = x;
        }
    }
    return ans;
}

/*
    只用关心子序列的最大值和最小值，与子序列的元素顺序无关。
    为了方便计算，先给数组排序。
    排序后，对于子数组来说，最大值与最小值之差<=k即可一组，
    原数组排好序了，子序列就是连续的。
    从左到右遍历数组，记录最小值min。如果nums[i] - min > k,
    说明nums[i]是下一段的最小值，把答案+1，更新min = nums[i]
*/

int main() {
    vector<int> arr = {3, 6, 1, 2, 5};
    int k = 2;
    cout << partitionArray(arr, k) << endl;
}

