#include "pch.h"

/*
    平方数之和只用遍历0-sqrt(c)即可，减少遍历时间
    使用int sum = l ^ 2 + r ^ 2;会溢出，导致结果出错
    方法一；遍历
    方法二：双指针
*/

bool judgeSquareSum(int c)
{
    int l = 0, r = sqrt(c);
    while (l <= r)
    {
        if (l * l == c - r * r)
        {
            return true;
        }
        if (l * l < c - r * r)
        {
            l++;
        }else
        {
            r--;
        }
        
    }
    return false;
}

int main()
{
    cout << judgeSquareSum(5) << endl;
}
