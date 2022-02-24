// 201312-2 ISBN号码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T4

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string str;   //定义string类型字符串
    cin >> str;

    int sum = 0;
    for (int i = 0, j = 1; i + 1 < str.size(); i++)
        if (str[i] != '-')
        {
            sum += (str[i] - '0') * j; //str[0]*1,字符转成数字ascii码
            j++;
        }

    sum %= 11; //模11 sum = sum%11
    char c = sum + '0'; //数字转换成字符
    if (sum == 10) c = 'X'; 

    if (str.back() == c) puts("Right");  //讲字符串的末尾是否相等
    else
    {
        str.back() = c;  //不等则赋值。
        cout << str << endl;
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
