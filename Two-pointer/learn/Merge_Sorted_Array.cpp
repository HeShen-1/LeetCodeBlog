#include "pch.h"

/*
    合并两个有序数组
    创建pos指针用于定位新数组的元素位置，是新数组的长度
    首先m、n是数组的长度，在数组中使用需要自减
    所以就有了：pos = m-- + n-- - 1
    在数组没有遍历完之前，也就是：m >= 0 && n >= 0
    比较nums1[m] > nums2[n]的大小，如果 nums1[m] 大，
    此时新数组的pos位置应该是nums1[m]，否则nums1[pos] = nums2[n]
    遍历完第一次之后，m、n、pos都需要自减进行下一次循环
    也就是：nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    如果nums1数组遍历完，nums2数组还没有遍历完，
    那么将nums2数组的数继续填充到新的nums1数组中

    为什么会有上面两个数组遍历不同步的情况
    因为原始的两个数组的长度不一致，但是由于新的数组的长度是m + n，
    所以nums2一定可以遍历完。可能存在m < n的情况，此时nums1遍历完成，而nums2未完成，
    所以有了以下代码
    while (n >= 0) {
        nums1[pos--] = nums2[n--];
    }

*/

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
        nums1[pos--] = nums2[n--];
    }
}



int main() {
    vector<int> n1 = {1, 2, 3, 0, 0, 0};
    vector<int> n2 = {2, 5, 6};
    int m = 3, n = 3;
    merge(n1, m, n2, n);
}
