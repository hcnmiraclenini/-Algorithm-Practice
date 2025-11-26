// 折半查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//折半查找找平方根
int main()
{
    int n;
    double k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        double left = 0, right = k;
        double mid = (left + right) / 2.0;
        double t = mid * mid;
        while (fabs(t - k) > 0.00001)
        {
            if (t < k) left = mid;
            else right = mid;
            mid = (left + right) / 2.0;
            t = mid * mid;
       }
        printf("%.3lf\n", mid);


    }



    return 0;
}

