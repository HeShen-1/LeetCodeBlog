#include "pch.h"

vector<int> partitionLabels(string s)
{
    int n = s.length();
    int last[26];
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        end = max(end, last[s[i] - 'a']);
        if (end == i)
        {
            /* code */
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<vector<int>> a = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    string s = "ababcbacadefegdehijhklij";
    // s = "eccbbbbdec"
    vector<int> ans = partitionLabels(s);

    for (const auto &item : ans)
    {
        cout << item << " ";
    }
    cout << endl;

}
