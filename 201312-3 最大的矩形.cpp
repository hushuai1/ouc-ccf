// 201312-3 最大的矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T3

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int h[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = i;
        while (l >= 1 && h[l] >= h[i]) l--; //向左拓展
        while (r <= n && h[r] >= h[i]) r++; //向右拓展
        res = max(res, h[i] * (r - l - 1)); //返回最大值
    }
    cout << res << endl;
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
