#include "pch.h"

bool checkPossibility(vector<int> &nums)
{
    int n = nums.size(), count = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = nums[i], y = nums[i + 1];
        if (x > y) {
            count++;
            if (count > 1) {
                return false;
            }
            if (i > 0 && y < nums[i - 1]) {
                nums[i + 1] = x;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> test = {4, 2, 1};
    cout << (checkPossibility(test) ? "true" : "false");
}
