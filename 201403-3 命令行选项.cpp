// 201403-3 命令行选项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T8

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 30;

int n;
bool o1[N], o2[N];//o1寸不带参数的，02寸带参数的
string ans[N];

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        if (i + 1 < str.size() && str[i + 1] == ':')
        {
            o2[str[i] - 'a'] = true;
            i++;
        }
        else o1[str[i] - 'a'] = true;

    cin >> n;//输入n行命令
    getchar();  // 将n后面的回车过滤掉
    for (int C = 1; C <= n; C++)
    {
        printf("Case %d:", C);
        getline(cin, str);
        stringstream ssin(str);
        vector<string> ops;//注意这是一个二维度的数组
        while (ssin >> str) ops.push_back(str);
        for (int i = 0; i < 26; i++) ans[i].clear();//数组初始化
        for (int i = 1; i < ops.size(); i++)
        {
            if (ops[i][0] != '-' || ops[i][1] < 'a' || ops[i].size() != 2) break;//判断是否合法
            int k = ops[i][1] - 'a';  //记录是哪个字母
            if (o1[k]) ans[k] = "*";  //如果不带参数，则标记为*
            else if (o2[k] && i + 1 < ops.size()) ans[k] = ops[i + 1], i++; //如果带参数而且不是最后一个元素，则赋值为后面的参数。会自动更新后面的参数，变成最后出现的参数
            else break;
        }
        for (int i = 0; i < 26; i++)//输出参数
            if (ans[i].size())
            {
                cout << " -" << (char)(i + 'a');
                if (o2[i]) cout << ' ' << ans[i];
            }
        cout << endl;
    }
    return 0;
}
样例输入
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
样例输出
Case 1: -a -l
Case 2:
Case 3: -w 15 -x
Case 4: -a -b

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
