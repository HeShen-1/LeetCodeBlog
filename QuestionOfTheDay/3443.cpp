#include "pch.h"

int maxDistance(string s, int k)
{
    int ans = 0;    // 记录最大距离
    int cnt['X']{}; // 统计每个方向字符出现次数（假设只用到大写字母）
    for (char ch : s)
    {
        cnt[ch]++;    // 当前字符计数加一
        int left = k; // 剩余可用操作次数，每次前缀独立计算
        // 定义一个lambda函数，计算两个方向的最大距离
        auto f = [&](int a, int b) -> int
        {
            int d = min({a, b, left}); // 能平衡的最大次数
            left -= d;                 // 扣除已用的操作次数
            return abs(a - b) + d * 2; // 平衡后剩余的距离+平衡带来的距离提升
        };
        // 计算当前前缀下南北和东西方向的最大距离之和
        ans = max(ans, f(cnt['N'], cnt['S']) + f(cnt['E'], cnt['W']));
    }
    return ans; // 返回最大距
}

int main()
{
    string s = "NWSE";
    cout << maxDistance(s, 1) << endl;
}
