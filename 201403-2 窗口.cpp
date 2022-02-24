// 201403-2 窗口.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T9

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int n, m;
struct Window
{
    int x1, y1, x2, y2;
    int id;
}w[N];

int get(int x, int y)
{
    for (int i = n; i; i--)//从最上面的窗口开始，找点是否在这个窗口的范围内
        if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2)
            return i;
    return 0;
}

int main()
{
    cin >> n >> m;  //输入n个窗口，m次点击
    // n行按照从最下层到最顶层的顺序给出 N 个窗口的位置
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        w[i] = { x1, y1, x2, y2, i };   //i=1表示在最下层
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;//输入点击的坐标点
        int t = get(x, y); //调用get函数
        if (!t) puts("IGNORED");
        else
        {
            cout << w[t].id << endl;
            auto r = w[t];  //将被点击的窗口移动到最上面，其余窗口的位置一次变换
            for (int i = t; i < n; i++) w[i] = w[i + 1];//在这个窗口前面的窗口全部下移
            w[n] = r;//被点击的窗口放在最前面
        }
    }

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
