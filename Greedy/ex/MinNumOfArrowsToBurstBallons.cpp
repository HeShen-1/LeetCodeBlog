#include "pch.h"

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });
    int ans = 0;
    long long pre = LLONG_MIN;
    for (auto &p : points)
    {
        if (p[0] > pre)
        { // 上一个点在区间左边
            ans++;
            pre = p[1]; // 在区间的最右边放一个点
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> a = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    vector<vector<int>> b = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    vector<vector<int>> c = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << findMinArrowShots(a) << endl;
}
