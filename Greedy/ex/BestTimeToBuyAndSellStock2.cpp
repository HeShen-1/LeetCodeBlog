#include "pch.h"

int maxProfit(vector<int> &prices)
{
    int f0 = 0, f1 = INT_MIN;
    for (int p : prices) 
    {
        /* code */
        int new_f0 = max(f0, f1 + p);
        f1 = max(f1, f0 - p);
        f0 = new_f0;
        cout << "f1=" << f1 << " f0=" << f0 << endl;
    }
    return f0;
}

int main()
{
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
}
