#include "pch.h"

string minWindow(string S, string T)
{
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    // 先统计T中的字符情况
    for (int i = 0; i < T.size(); ++i) {
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    // 移动滑动窗口，不断更改统计数据
    int count = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for (int r = 0; r < S.size(); ++r) {
        if (flag[S[r]]) {
            if (--chars[S[r]] >= 0) {
                ++count;
            }
            // 若目前滑动窗口已包含T中全部字符
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (count == T.size()) {
                if (r - l + 1 < min_size) {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[S[l]] && ++chars[S[l]] > 0) {
                    --count;
                }
                ++l;
            }
        }
    }
    return min_size > S.size() ? "" : S.substr(min_l, min_size);
}

/*
    使用滑动窗口: 即两个指针l、r都是从左到右移动，且l的位置一定在r的左边或重合。
    虽然题解中for循环出现一个while循环，但是while循环负责移动l指针，
    且l只会从左到右遍历一次，时间复杂度在O(n)
    本题使用长度为128的数组来映射字符，也可以用哈希表来代替;
    其中chars表示目前每个字符缺少的数量，flag表示每个字符是否在T中存在

*/

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
}