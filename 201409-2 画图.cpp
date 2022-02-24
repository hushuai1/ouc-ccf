// 201409-2 画图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T15

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
bool st[N][N];

int main()
{
    cin >> n;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                st[i][j] = true;
    }
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res += st[i][j];
    cout << res << endl;

    return 0;
}

//思考？如果让你求重叠的方块个数呢？
答：可以将st[i][j]定义为int型数组，每访问一次st[i][j]++，最后判断值为2的就是重叠的方块了，并计数

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
