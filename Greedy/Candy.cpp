#include "pch.h"

int func(vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2) {
		return size;
	}
	cout << "Traverse from left to right:";
	vector<int> num(size, 1);
	for (int i = 1; i < size; ++i) {
		if (ratings[i] > ratings[i - 1]) {
			num[i] = num[i - 1] + 1;
		}
		cout << num[i - 1] << " ";
	}
	cout << num[2] << endl;
	for (int i = size - 1; i > 0; --i) {
		if (ratings[i] < ratings[i - 1]) {
			num[i - 1] = max(num[i - 1], num[i - 1] + 1);
		}
	}
	
	cout << "Traverse from right to left:";
	for (const auto& n : num) {
        cout << n << " ";
    }

	return accumulate(num.begin(), num.end(), 0);
}

int main() {
	vector<int> a = {1, 0, 2};
	int ans = func(a);
	cout << endl;
	cout << ans << endl;
}