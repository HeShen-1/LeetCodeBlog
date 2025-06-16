#include "pch.h"

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
