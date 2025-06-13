#include "pch.h"


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int size = flowerbed.size();
    for (int i = 1; i + 1 < size; i++) {
        if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
}

int main()
{
    vector<int> a = {1, 0, 0, 0, 1};
    // vector<int> b = {1, 2, 3};
    int n = 2;
    bool ans = canPlaceFlowers(a, n);
    cout << endl;

    cout << (ans ? "true" : "false") << endl;
}