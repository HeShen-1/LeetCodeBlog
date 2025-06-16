#include "pch.h"

int func(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return 0;
    }
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });

    for (size_t i = 0; i < intervals.size(); ++i)
    {
        for (size_t j = 0; j < intervals[i].size(); ++j)
        {
            cout << "[" << i << "][" << j << "]=" << intervals[i][j] << " ";
        }
        cout << endl;
    }

    int total = 0, prev = intervals[0][1];
    cout << "initial valueoutput:total=" << total << " prev=" << prev << endl;
    for (int i = 1; i < n; ++i)
    {
        if (intervals[i][0] < prev)
        {
            /* code */
            ++total;
        }
        else
        {
            prev = intervals[i][1];
        }
        cout << "procedure value output:total=" << total << " prev=" << prev << endl;
    }
    return total;
}

int main()
{
    vector<vector<int>> a = {{1, 2}, {2, 4}, {1, 3}};
    // vector<int> b = {1, 2, 3};
    int ans = func(a);
    cout << ans << endl;
}