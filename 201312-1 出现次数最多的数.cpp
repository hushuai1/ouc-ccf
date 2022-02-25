// 201312-1 出现次数最多的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T5

// #include <iostream>
// #include <cstring>
// #include <algorithm>
#include<bits/stdc++.h> //万能头文件
using namespace std;

const int N = 10010; //定义数组空间大小

int n;
int s[N];    //定义数组，s[10010]表示数组里面最多可以放10010个元素

int main()
{
    //freopen("test.txt","r",stdin);
    cin >> n;    //n表示输入多少个数
    while (n--)  //为什么不是--n?
    {
        int x;
        cin >> x;   //输入元素
        s[x] ++;    //元素做数组下标方便计数
    }

    int res = 0;
    for (int i = 1; i < N; i++)  //遍历一遍数组，找到出现次数最多的，返回其索引。
        if (s[i] > s[res])
            res = i;

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
